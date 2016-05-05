#pragma once

#include "macros.h"

namespace render
{
	// ��ƵͼƬ֡
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

	// ffmpeg ����
	class FFmpeg : public Media, public IMediaLoader
	{
	public:
		FFmpeg();
		virtual ~FFmpeg();
	public:
		// ������Ƶ
		virtual void load(const MediaDefine& mediaDefine);
		// ��ȡ��һ֡��Ƶ
		virtual Image* getNextVideo();
		// ������Ƶ֡λ��
		virtual void setVideoFrame(mf_s frame);
	protected:
		// ����ffm
		void loadFFM(const MediaDefine& mediaDefine);
	private:
		int _videoStream;
		VideoFrameImage _image;
	};
}