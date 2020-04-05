#include "MediaFFmpeg.h"
#include "ext-config.h"
#include <string>

#include "Graphic/GLAPI/macros.h"

using namespace render;

#pragma warning(disable:4996)

//////////////////////////////////////////////////////////////////////////
bool MediaFFmpeg::s_bInitFFmpeg = false;

void createVideoImage(const AVFrame* frame, AVCodecContext* pCodecContext, VideoFrameImage* image)
{
	if (frame == nullptr || image == nullptr)
	{
		return;
	}

	uint32_t width = frame->width;
	uint32_t height = frame->height;

	PixelFormat glFormat = PixelFormat::RGB;
	TextureParameter glInternalFormat = TextureParameter::THREE;

	int destSize = av_image_get_buffer_size(AV_PIX_FMT_RGB24, width, height, 1);
	uint8_t* destPixels = (uint8_t *)malloc(sizeof (uint8_t)* destSize);
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

	int mid = destSize / 2;
	for (int i = 0; i < mid; i++)
	{
		uint8_t c = destPixels[i];
		destPixels[i] = destPixels[destSize - i - 1];
		destPixels[destSize - i - 1] = c;
	}

	image->init(glFormat, glInternalFormat, destPixels, width, height);
}

void createVideoAudio(const AVFrame* frame, AVCodecContext* pCodecContext, VideoAudioClip* audio)
{
	int frameBufSize = av_samples_get_buffer_size(NULL, pCodecContext->channels, frame->nb_samples, pCodecContext->sample_fmt, 1);

	int eachChannelSize = frame->linesize[0];
	uint8_t* frameBuf = new uint8_t[frameBufSize];
	
	for (int ch = 0; ch < pCodecContext->channels; ch++)
	{
		for (int i = 0; i < frame->nb_samples; i++)
		{
			frameBuf[i * 2 + ch] = frame->data[ch][i];
		}
	}
	
	//memcpy(frameBuf, frame->data[0], frameBufSize* sizeof(char));

	FMOD_SOUND_FORMAT format = FMOD_SOUND_FORMAT_NONE;
	if (frame->format == AV_SAMPLE_FMT_U8 || frame->format == AV_SAMPLE_FMT_U8P)
	{
		format = FMOD_SOUND_FORMAT_PCM8;
	}
	else if (frame->format == AV_SAMPLE_FMT_S16 || frame->format == AV_SAMPLE_FMT_S16P)
	{
		format = FMOD_SOUND_FORMAT_PCM16;
	}
	else if (frame->format == AV_SAMPLE_FMT_S32 || frame->format == AV_SAMPLE_FMT_S32P)
	{
		format = FMOD_SOUND_FORMAT_PCM32;
	}
	else if (frame->format == AV_SAMPLE_FMT_FLT || frame->format == AV_SAMPLE_FMT_FLTP)
	{
		format = FMOD_SOUND_FORMAT_PCMFLOAT;
	}
	else
	{
		format = FMOD_SOUND_FORMAT_BITSTREAM;
	}

	audio->init(frameBuf, frameBufSize, pCodecContext->channels, pCodecContext->channel_layout, format, frame->sample_rate, frame->nb_samples);
}

void createVideoTitle(const AVSubtitle* subTitle, AVCodecContext* pCodecContext, std::string* title)
{

}

//////////////////////////////////////////////////////////////////////////
VideoFrameImage::VideoFrameImage()
{
	
}

VideoFrameImage::~VideoFrameImage()
{

}

void VideoFrameImage::init(PixelFormat format, TextureParameter internalFormat, uint8_t* pixels, uint32_t width, uint32_t height)
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

void VideoAudioClip::init(uint8_t* data, int frameSize, int channels, int64_t channelLayout, int format, int frequency, int samples)
{
	this->setData(data);
	this->setSize(frameSize);
	this->setChannelLayout(channelLayout);
	this->setChannels(channels);
	this->setFormat(format);
	this->setFrequency(frequency);
	this->setSamples(samples);
}

void VideoAudioClip::init(uint8_t* data, int frameSize)
{
	this->setData(data);
	this->setSize(frameSize);
}


//////////////////////////////////////////////////////////////////////////
MediaFFmpeg::MediaFFmpeg()
:_videoStream(-1)
, _audioStream(-1)
, _subTitleStream(-1)
, _formatContext(nullptr)
{
	_text = "";
}

MediaFFmpeg::~MediaFFmpeg()
{
	disposeFFM();
}

void MediaFFmpeg::load(const MediaDefine& mediaDefine)
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


ImageDetail* MediaFFmpeg::getNextPicture()
{
	return &_image;
}

AudioDetail* MediaFFmpeg::getNextAudio()
{
	return &_audio;
}

std::string MediaFFmpeg::getNextTitle()
{
	return _text;
}

void MediaFFmpeg::autoNextFrame()
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
				createVideoImage(videoFrame, pCodecContext, &_image);
			}
		}
		got_audio = 0;
		if (packet->stream_index == _audioStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;
			error = avcodec_decode_audio4(pCodecContext, audioFrame, &got_audio, packet);
			if (error >= 0 && got_audio)
			{
				createVideoAudio(audioFrame, pCodecContext, &_audio);
			}
		}
		got_title = 0;
		if (packet->stream_index == _subTitleStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;
			error = avcodec_decode_subtitle2(pCodecContext, &subTitle, &got_title, packet);
			if (error >= 0 && got_title)
			{
				createVideoTitle(&subTitle, pCodecContext, &_text);
			}
		}
	}

	av_frame_free(&videoFrame);
	av_frame_free(&audioFrame);

	av_packet_free(&packet);

}
void MediaFFmpeg::setVideoFrame(mf_s frame)
{
	AVRational bqTimebase;
	bqTimebase.den = 1000;
	bqTimebase.num = 1;

	AVRational timeBase = _formatContext->streams[_videoStream]->time_base;

	uint64_t timestamp = (uint64_t)(frame * 1000);
	timestamp = (uint64_t)(av_rescale_q(timestamp, bqTimebase, timeBase));

	av_seek_frame(_formatContext, _videoStream, timestamp, AVSEEK_FLAG_BACKWARD);
}

void MediaFFmpeg::loadFFM(const MediaDefine& mediaDefine)
{
	std::string fullpath = G_FILEPATH->getFilePath(mediaDefine.filepath);
	initFFmpeg(fullpath);

	getStreamIndex(AVMEDIA_TYPE_VIDEO, _videoStream);

	getStreamIndex(AVMEDIA_TYPE_AUDIO, _audioStream);

	getStreamIndex(AVMEDIA_TYPE_SUBTITLE, _subTitleStream);
}

void MediaFFmpeg::disposeFFM()
{
	if (_formatContext)
	{
		avformat_close_input(&_formatContext);
	}
}

void MediaFFmpeg::initFFmpeg(const std::string& path)
{
	if (!s_bInitFFmpeg)
	{
		av_register_all();
		s_bInitFFmpeg = true; 
	}

	disposeFFM();

	if (avformat_open_input(&_formatContext, path.c_str(), 0, nullptr) < 0)
	{
		return;
	}

	if (avformat_find_stream_info(_formatContext, nullptr) < 0)
	{
		return;
	}
}


void MediaFFmpeg::getStreamIndex(int type, int& streamIndex)
{
	if (_formatContext == nullptr)
	{
		return;
	}
	/*
	for (uint32_t i = 0; i < _formatContext->nb_streams; i++)
	{
		if ((_formatContext->streams[i])->codec->codec_type == type)
		{
			streamIndex = i;
			break;
		}
	}
	if (streamIndex < 0)
	{
		return;
	}
	AVCodecContext* codecContext = _formatContext->streams[streamIndex]->codec;
	AVCodec* codec = avcodec_find_decoder(codecContext->codec_id);
	if (codec == nullptr)
	{
		return;
	}
	*/
	AVCodec* codec = nullptr;
	streamIndex = av_find_best_stream(_formatContext, (AVMediaType)type, -1, -1, &codec, 0);
	if (streamIndex < 0)
	{
		return;
	}

	AVCodecContext* codecContext = _formatContext->streams[streamIndex]->codec;
	if (avcodec_open2(codecContext, codec, nullptr) < 0)
	{
		return;
	}
}


