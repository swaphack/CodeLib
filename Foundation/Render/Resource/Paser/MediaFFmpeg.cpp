#include "MediaFFmpeg.h"
#include "ext-config.h"
#include "system.h"
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

	int nUnitSize = 3;
	int nWidth = width * nUnitSize;
	for (int i = 0; i < (height / 2); i++)
	{
		for (int j = 0; j < width; j++)
		{
			int nSrc = j * nUnitSize + i * nWidth;
			int nDest = j * nUnitSize + (height - i - 1) * nWidth;

			uint8_t r = destPixels[nSrc + 0];
			uint8_t g = destPixels[nSrc + 1];
			uint8_t b = destPixels[nSrc + 2];

			destPixels[nSrc + 0] = destPixels[nDest + 0];
			destPixels[nSrc + 1] = destPixels[nDest + 1];
			destPixels[nSrc + 2] = destPixels[nDest + 2];

			destPixels[nDest + 0] = r;
			destPixels[nDest + 1] = g;
			destPixels[nDest + 2] = b;
		}
	}
	image->init(glFormat, glInternalFormat, destPixels, width, height, nUnitSize);

	free(destPixels);
}

void createVideoAudio(const AVFrame* frame, AVCodecContext* pCodecContext, VideoAudioClip* audio)
{
	AVSampleFormat destFmt = AV_SAMPLE_FMT_S16;
	FMOD_SOUND_FORMAT format = FMOD_SOUND_FORMAT_PCM16;

	int nPerSize = av_get_bytes_per_sample(destFmt);

	struct SwrContext* swr_covert_ctx = swr_alloc_set_opts(NULL,
		av_get_default_channel_layout(pCodecContext->channels), destFmt, pCodecContext->sample_rate,
		av_get_default_channel_layout(pCodecContext->channels), pCodecContext->sample_fmt, pCodecContext->sample_rate,
		0, NULL);//转换上下文

	swr_init(swr_covert_ctx);//初始化上下文

	int frameSize = av_samples_get_buffer_size(NULL, frame->channels, frame->nb_samples, destFmt, 1);
	uint8_t* frameBuf = (uint8_t*)malloc(frameSize);
	int samplenums = swr_convert(swr_covert_ctx, &frameBuf, frameSize, (const uint8_t **)frame->data, frame->nb_samples);

	/*
	uint8_t* orderBuf = (uint8_t*)malloc(frameSize);
	for (int i = 0; i < frame->nb_samples; i++)
	{
		for (int j = 0; j < frame->channels; j++)
		{
			memcpy(orderBuf + i * nPerSize + j * nPerSize, frameBuf + j * nPerSize * frame->nb_samples + i * nPerSize, nPerSize);
		}
	}
	*/
	
	swr_free(&swr_covert_ctx);

	audio->init(frameBuf, frameSize, pCodecContext->channels, pCodecContext->channel_layout, format, frame->sample_rate, frame->nb_samples);

	free(frameBuf);
	//free(orderBuf);
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

void VideoFrameImage::init(PixelFormat format, TextureParameter internalFormat, uint8_t* pixels, uint32_t width, uint32_t height, int nUnitSize)
{
	this->setFormat(format);
	this->setInternalFormat(internalFormat);
	this->setPixels(pixels, width, height, nUnitSize);
}
//////////////////////////////////////////////////////////////////////////

VideoAudioClip::VideoAudioClip()
{

}

VideoAudioClip::VideoAudioClip(const VideoAudioClip& detail)
{
	this->setData(detail.getData(), detail.getSize());
	this->setChannels(detail.getChannels());
	this->setChannelLayout(detail.getChannelLayout());
	this->setFormat(detail.getFormat());
	this->setFrequency(detail.getFrequency());
	this->setSamples(detail.getSamples());
}

VideoAudioClip::~VideoAudioClip()
{

}

void VideoAudioClip::init(uint8_t* data, int frameSize, int channels, int64_t channelLayout, int format, int frequency, int samples)
{
	this->setData(data, frameSize);
	this->setChannelLayout(channelLayout);
	this->setChannels(channels);
	this->setFormat(format);
	this->setFrequency(frequency);
	this->setSamples(samples);
}

void VideoAudioClip::init(uint8_t* data, int frameSize)
{
	this->setData(data, frameSize);
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
	disposeFormatContext();
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
	if (!s_bInitFFmpeg)
	{
		av_register_all();
		s_bInitFFmpeg = true;
	}

	disposeFormatContext();

	do
	{
		if (loadFromLocalFile(mediaDefine.filepath))
		{
			break;
		}
		if (loadFromRemoteUrl(mediaDefine.filepath))
		{
			break;
		}

		return;
	} while (true);

	getStreamIndex(AVMEDIA_TYPE_VIDEO, _videoStream);

	getStreamIndex(AVMEDIA_TYPE_AUDIO, _audioStream);

	getStreamIndex(AVMEDIA_TYPE_SUBTITLE, _subTitleStream);
}

void MediaFFmpeg::disposeFormatContext()
{
	if (_formatContext)
	{
		avformat_close_input(&_formatContext);
	}
}

bool MediaFFmpeg::loadFromLocalFile(const std::string& path)
{
	std::string fullpath = G_FILEPATH->getFilePath(path);
	if (fullpath.empty())
	{
		return false;
	}

	if (avformat_open_input(&_formatContext, path.c_str(), 0, nullptr) < 0)
	{
		return false;
	}

	if (avformat_find_stream_info(_formatContext, nullptr) < 0)
	{
		return false;
	}

	return true;
}

bool MediaFFmpeg::loadFromRemoteUrl(const std::string& path)
{
	std::string localFilePath = "temp.txt";
	sys::Directory::createFile(localFilePath);

	sys::ConcurrentFile file(localFilePath);

	sys::HttpDownload download;
	download.startTask(path, "", [&](int32_t tag, const std::string& content){
		file.write(content.c_str(), content.size());
	});

	return true;
}

void MediaFFmpeg::getStreamIndex(int type, int& streamIndex)
{
	if (_formatContext == nullptr)
	{
		return;
	}

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

