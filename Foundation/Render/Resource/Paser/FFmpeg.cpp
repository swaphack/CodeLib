#include "FFmpeg.h"
#include "ext-config.h"
#include <string>

using namespace render;

#pragma warning(disable:4996)

//////////////////////////////////////////////////////////////////////////
bool FFmpeg::s_bInitFFmpeg = false;

void createVideoImage(const AVFrame* frame, VideoFrameImage* image)
{
	if (frame == nullptr || image == nullptr)
	{
		return;
	}

	uint width = frame->width;
	uint height = frame->height;

	int glFormat = GL_RGB;
	int glInternalFormat = 3;

	int destSize = av_image_get_buffer_size(AV_PIX_FMT_RGB24, width, height, 1);
	uchar* destPixels = (uchar *)malloc(sizeof (uchar)* destSize);
	memset(destPixels, 0, destSize);
	
	AVFrame* destFrame = av_frame_alloc();
	av_image_fill_arrays(destFrame->data, destFrame->linesize, destPixels, AV_PIX_FMT_RGB24, width, height, 1);

	struct SwsContext* pContext = sws_getContext(width, height, (AVPixelFormat)frame->format,
		width, height, AV_PIX_FMT_RGB24,
		SWS_BICUBIC, nullptr, nullptr, nullptr);

	sws_scale(pContext,
		frame->data, frame->linesize, 
		0, height,
		destFrame->data, destFrame->linesize);

	sws_freeContext(pContext);

	av_frame_free(&destFrame);

	image->init(glFormat, glInternalFormat, destPixels, width, height);
}

void createVideoAudio(const AVFrame* frame, VideoAudioClip* audio)
{
	if (frame == nullptr || audio == nullptr)
	{
		return;
	}

	int dataSize = 0;
	int resampledDataSize = 0;
	int64_t decChannelLayout;
	int channels = 0;
	int nbChannels = 0;

	channels = av_frame_get_channels(frame);
	dataSize = av_samples_get_buffer_size(nullptr, channels, frame->nb_samples, (AVSampleFormat)frame->format, 1);

	if (dataSize <= 0)
	{
		audio->init(nullptr, 0);
		return;
	}

	nbChannels = av_get_channel_layout_nb_channels(frame->channel_layout);

	if (frame->channel_layout && channels == nbChannels)
	{
		decChannelLayout = frame->channel_layout;
	}
	else
	{
		decChannelLayout = av_get_default_channel_layout(channels);
	}

	/*
	AVSampleFormat destFormat = AV_SAMPLE_FMT_U8;
	int destChannel = 1;

	AVFrame* destFrame = av_frame_alloc();
	av_samples_alloc(destFrame->data, destFrame->linesize, nbChannels, frame->nb_samples, destFormat, 1);
	struct SwrContext* pContext = swr_alloc_set_opts(NULL,
		decChannelLayout, destFormat, frame->sample_rate,
		decChannelLayout, (AVSampleFormat)frame->format, frame->sample_rate,
		0, NULL);

	int outCount = frame->nb_samples + 256;
	int outSize = av_samples_get_buffer_size(nullptr, destChannel, outCount, destFormat, 0);
	if (outSize == 0)
	{
		swr_free(&pContext);
		return;
	}
	const uint8_t **in = (const uint8_t **)frame->extended_data;
	uchar* destData = (uchar*)malloc(outCount);	
	memset(destData, 0, outCount);
	uint destDataSize = outSize;
	uint8_t **out = &destData;
	//av_fast_malloc(destData, &destDataSize, outSize);
	if (!destData)
	{
		swr_free(&pContext);
		return;
	}
	int cvtLen = swr_convert(pContext, out, outCount, in, frame->nb_samples);
	if (cvtLen < 0)
	{
		swr_free(&pContext);
		return;
	}

	swr_free(&pContext);
	int totalSize = cvtLen * destChannel * av_get_bytes_per_sample(destFormat);
	*/

	uchar* destData = (uchar*)malloc(dataSize);
	memset(destData, 0, dataSize);
	//memcpy(destData, frame->extended_data, totalSize);

	for (int i = 0; i < frame->linesize[0]; i++)
	{
		for (int j = 0; j < nbChannels; j++)
		{
			if (frame->extended_data[j][i])
			{
				destData[nbChannels * i + j] = frame->extended_data[j][i];
			}
		}
	}

	audio->init(destData, dataSize, nbChannels, decChannelLayout, frame->format, frame->sample_rate, frame->nb_samples);
}

void createVideoTitle(const AVSubtitle* subTitle, std::string* title)
{

}

//////////////////////////////////////////////////////////////////////////
VideoFrameImage::VideoFrameImage()
{
	
}

VideoFrameImage::~VideoFrameImage()
{

}

void VideoFrameImage::init(int format, int internalFormat, uchar* pixels, uint width, uint height)
{
	this->setFormat(format);
	this->setInternalFormat(internalFormat);
	this->setPixels(pixels);
	this->setWidth(width);
	this->setHeight(height);
}
//////////////////////////////////////////////////////////////////////////

VideoAudioClip::VideoAudioClip()
{

}

VideoAudioClip::~VideoAudioClip()
{

}

void VideoAudioClip::init(uchar* data, int frameSize, int channels, int64_t channelLayout, int format, int frequency, int samples)
{
	this->setData(data);
	this->setSize(frameSize);
	this->setChannelLayout(channelLayout);
	this->setChannels(channels);
	this->setFormat(format);
	this->setFrequency(frequency);
	this->setSamples(samples);
}

void VideoAudioClip::init(uchar* data, int frameSize)
{
	this->setData(data);
	this->setSize(frameSize);
}


//////////////////////////////////////////////////////////////////////////
FFmpeg::FFmpeg()
:_videoStream(-1)
, _audioStream(-1)
, _subTitleStream(-1)
, _formatContext(nullptr)
{
	_text = "";
}

FFmpeg::~FFmpeg()
{
	disposeFFM();
}

void FFmpeg::load(const MediaDefine& mediaDefine)
{
	this->loadFFM(mediaDefine);

	if (_formatContext == nullptr)
	{
		return;
	}
	
	AVStream* stream = _formatContext->streams[_videoStream];
	/*AVCodecContext* pCodecContext = stream->codec;*/
	AVCodecParameters* pParameters = stream->codecpar;

	this->setWidth(pParameters->width);
	this->setHeight(pParameters->height);

	float time = (float)(1.0f * stream->duration * av_q2d(stream->time_base));
	this->setTime(time);

	float fps = (float)(av_q2d(stream->r_frame_rate));
// 	if (fps < 0)
// 	{
// 		fps = (float)(1.0f / av_q2d(stream->codec->time_base));
// 	}

	this->setFrameRate(fps);
}


Image* FFmpeg::getNextPicture()
{
	return &_image;
}

Audio* FFmpeg::getNextAudio()
{
	return &_audio;
}

std::string FFmpeg::getNextTitle()
{
	return _text;
}

void FFmpeg::autoNextFrame()
{
	// 解析每一帧数据
	int got_picture = 0;
	int got_audio = 0;
	int got_title = 0;
	int error = 0;

	AVPacket* packet = av_packet_alloc();
	AVFrame* videoFrame = av_frame_alloc();
	AVFrame* audioFrame = av_frame_alloc();

	AVSubtitle subTitle;
	AVCodecContext* pCodecContext = nullptr;

	if (av_read_frame(_formatContext, packet) >= 0)
	{
		if (packet->stream_index == _videoStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;

			error = avcodec_decode_video2(pCodecContext, videoFrame, &got_picture, packet);
			if (error >= 0 && got_picture)
			{
				createVideoImage(videoFrame, &_image);
			}
		}
		got_audio = 0;
		if (packet->stream_index == _audioStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;
			error = avcodec_decode_audio4(pCodecContext, audioFrame, &got_audio, packet);
			if (error >= 0 && got_audio)
			{
				createVideoAudio(audioFrame, &_audio);
			}
		}
		got_title = 0;
		if (packet->stream_index == _subTitleStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;
			error = avcodec_decode_subtitle2(pCodecContext, &subTitle, &got_title, packet);
			if (error >= 0 && got_title)
			{
				createVideoTitle(&subTitle, &_text);
			}
		}
	}

	av_frame_free(&videoFrame);
	av_frame_free(&audioFrame);

	av_packet_free(&packet);

}
void FFmpeg::setVideoFrame(mf_s frame)
{
	AVRational bqTimebase;
	bqTimebase.den = 1000;
	bqTimebase.num = 1;

	AVRational timeBase = _formatContext->streams[_videoStream]->time_base;

	ulong timestamp = (ulong)(frame * 1000);
	timestamp = (ulong)(av_rescale_q(timestamp, bqTimebase, timeBase));

	av_seek_frame(_formatContext, _videoStream, timestamp, AVSEEK_FLAG_BACKWARD);
}

void FFmpeg::loadFFM(const MediaDefine& mediaDefine)
{
	std::string fullpath = G_FILEPATH->getFilePath(mediaDefine.filepath.c_str());
	initFFmpeg(fullpath.c_str());

	getStreamIndex(AVMEDIA_TYPE_VIDEO, _videoStream);

	getStreamIndex(AVMEDIA_TYPE_AUDIO, _audioStream);

	getStreamIndex(AVMEDIA_TYPE_SUBTITLE, _subTitleStream);
}

void FFmpeg::disposeFFM()
{
	if (_formatContext)
	{
		avformat_close_input(&_formatContext);
	}
}

void FFmpeg::initFFmpeg(const char* path)
{
	if (!s_bInitFFmpeg)
	{
		av_register_all();
		s_bInitFFmpeg = true;
	}

	disposeFFM();

	avformat_open_input(&_formatContext, path, 0, nullptr);

	if (avformat_find_stream_info(_formatContext, nullptr) < 0)
	{
		return;
	}
}


void FFmpeg::getStreamIndex(int type, int& streamIndex)
{
	if (_formatContext == nullptr)
	{
		return;
	}
	for (uint i = 0; i < _formatContext->nb_streams; i++)
	{
		if ((_formatContext->streams[i])->codec->codec_type == type)
		{
			streamIndex = i;
			break;
		}
	}

	if (streamIndex == -1)
	{
		return;
	}

	AVCodecContext* codecContext = _formatContext->streams[streamIndex]->codec;
	AVCodec* codec = avcodec_find_decoder(codecContext->codec_id);
	if (codec == nullptr)
	{
		return;
	}

	avcodec_open2(codecContext, codec, nullptr);
}


