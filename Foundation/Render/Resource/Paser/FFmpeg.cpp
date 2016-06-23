#include "FFmpeg.h"

#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/pixdesc.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
#ifdef __cplusplus
}
#endif

using namespace render;

//////////////////////////////////////////////////////////////////////////
bool FFmpeg::s_bInitFFmpeg = false;

void createNewVideoFrame(const AVFrame* frame, AVPixelFormat format, VideoFrameImage* image)
{
	if (image == nullptr)
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

	struct SwsContext* swsContext = sws_getContext(width, height, format,
		width, height, AV_PIX_FMT_RGB24,
		SWS_BICUBIC, nullptr, nullptr, nullptr);

	sws_scale(swsContext, 
		frame->data, frame->linesize, 
		0, height,
		destFrame->data, destFrame->linesize);

	sws_freeContext(swsContext);

	av_frame_free(&destFrame);

	image->init(glFormat, glInternalFormat, destPixels, width, height);
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
	SAFE_FREE(_pixels);

	this->setFormat(format);
	this->setInternalFormat(internalFormat);
	this->setPixels(pixels);
	this->setWidth(width);
	this->setHeight(height);
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
	
	AVStream* stream = _formatContext->streams[_videoStream];
	AVCodecContext* pCodecContext = stream->codec;

	this->setWidth(pCodecContext->width);
	this->setHeight(pCodecContext->height);

	float time = 1.0f * stream->duration * av_q2d(stream->time_base);
	this->setTime(time);

	float fps = av_q2d(stream->r_frame_rate);
	if (fps < 0)
	{
		fps = 1.0f / av_q2d(stream->codec->time_base);
	}

	this->setFrameRate(fps);
}


Image* FFmpeg::getNextVideo()
{
	return &_image;
}

void FFmpeg::autoNextFrame()
{
	// ����ÿһ֡����
	int got_picture = 0;
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
				createNewVideoFrame(videoFrame, pCodecContext->pix_fmt, &_image);
			}
		}
		got_picture = 0;
		if (packet->stream_index == _audioStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;
			error = avcodec_decode_audio4(pCodecContext, audioFrame, &got_picture, packet);
			if (error >= 0 && got_picture)
			{

			}
		}
		got_picture = 0;
		if (packet->stream_index == _subTitleStream)
		{
			pCodecContext = _formatContext->streams[packet->stream_index]->codec;
			error = avcodec_decode_subtitle2(pCodecContext, &subTitle, &got_picture, packet);
			if (error >= 0 && got_picture)
			{

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

	ulong timestamp = frame * 1000;
	timestamp = av_rescale_q(timestamp, bqTimebase, timeBase);

	av_seek_frame(_formatContext, _videoStream, timestamp, AVSEEK_FLAG_BACKWARD);
}

void FFmpeg::loadFFM(const MediaDefine& mediaDefine)
{
	initFFmpeg(mediaDefine.filepath.c_str());

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