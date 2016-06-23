#pragma once

#include "macros.h"

struct AVFormatContext;

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
		// 自动跳转到下一帧
		virtual void autoNextFrame();
		// 设置视频帧位置
		virtual void setVideoFrame(mf_s frame);
	protected:
		// 加载ffm
		void loadFFM(const MediaDefine& mediaDefine);
		// 初始化
		void initFFmpeg(const char* path);
		// 卸载ffm
		void disposeFFM();

		void getStreamIndex(int type, int& streamIndex);
	private:
		// 视频流位置
		int _videoStream;
		// 音频流位置
		int _audioStream;
		// 标题流位置
		int _subTitleStream;
		// 图片
		VideoFrameImage _image;
		// 文本
		std::string _text;
		AVFormatContext* _formatContext;
		// 是否初始化ffm
		static bool s_bInitFFmpeg;
	};
}