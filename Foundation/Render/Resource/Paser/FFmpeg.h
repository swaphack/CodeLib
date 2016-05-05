#pragma once

#include "macros.h"

namespace render
{
	// 视频图片帧
	class VideoFrameImage : public Image
	{
	public:
		VideoFrameImage();
		virtual ~VideoFrameImage();
	public:
		void init(int format, int internalFormat, uchar* pixels, uint width, uint height);
	protected:
	private:
	};

	// ffmpeg 解析
	class FFmpeg : public Media, public IMediaLoader
	{
	public:
		FFmpeg();
		virtual ~FFmpeg();
	public:
		// 加载视频
		virtual void load(const MediaDefine& mediaDefine);
		// 获取下一帧视频
		virtual Image* getNextVideo();
		// 设置视频帧位置
		virtual void setVideoFrame(mf_s frame);
	protected:
		// 加载ffm
		void loadFFM(const MediaDefine& mediaDefine);
	private:
		int _videoStream;
		VideoFrameImage _image;
	};
}