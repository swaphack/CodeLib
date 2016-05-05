#include "FFmpeg.h"

using namespace render;

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

//////////////////////////////////////////////////////////////////////////
bool _bInitFFmpeg = false;
AVFormatContext* _formatContext = nullptr;
AVCodecContext* _codecContext = nullptr;

void disposeFFM()
{
	if (_codecContext)
	{
		avcodec_close(_codecContext);
	}

	if (_formatContext)
	{
		avformat_close_input(&_formatContext);
	}
}

void initFFmpeg(const char* path)
{
	if (!_bInitFFmpeg)
	{
		av_register_all();
		_bInitFFmpeg = true;
	}

	disposeFFM();

	avformat_open_input(&_formatContext, path, 0, nullptr);

	if (avformat_find_stream_info(_formatContext, nullptr) < 0)
	{
		return;
	}
}

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

void setStreamType(int type, int& streamIndex)
{
	if (_formatContext == nullptr)
	{
		return;
	}
	for (int i = 0; i < _formatContext->nb_streams; i++)
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

	_codecContext = _formatContext->streams[streamIndex]->codec;
	AVCodec* codec = avcodec_find_decoder(_codecContext->codec_id);
	if (codec == nullptr)
	{
		return;
	}

	avcodec_open2(_codecContext, codec, nullptr);
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
{
	
}

FFmpeg::~FFmpeg()
{
	disposeFFM();
}

void FFmpeg::load(const MediaDefine& mediaDefine)
{
	this->loadFFM(mediaDefine);

	this->setWidth(_codecContext->width);
	this->setHeight(_codecContext->height);
	
	AVStream* stream = _formatContext->streams[_videoStream];

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
	// 解析每一帧数据
	int got_picture = 0;
	int error = 0;

	AVPacket* packet = av_packet_alloc();
	AVFrame* frame = av_frame_alloc();

	if (av_read_frame(_formatContext, packet) >= 0)
	{
		if (packet->stream_index == _videoStream)
		{
			error = avcodec_decode_video2(_codecContext, frame, &got_picture, packet);
			if (error >= 0)
			{
				if (got_picture)
				{
					// 内存泄漏
					createNewVideoFrame(frame, _codecContext->pix_fmt, &_image);
				}
			}
		}
	}

	av_frame_free(&frame);
	av_packet_free(&packet);

	return &_image;
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

	setStreamType(AVMEDIA_TYPE_VIDEO, _videoStream);
}