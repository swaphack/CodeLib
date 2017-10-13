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

	// 音频片段
	class VideoAudioClip : public Audio
	{
	public:
		VideoAudioClip();
		virtual ~VideoAudioClip();
	public:
		void init(uchar* data, int frameSize);
		void init(uchar* data, int frameSize, int channels, int64_t channelLayout, int format, int frequency, int samples);
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
		virtual Image* getNextPicture();
		// 获取下一帧音频图片
		virtual Audio* getNextAudio();
		// 获取下一帧标题
		virtual std::string getNextTitle();
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
		// 音频
		VideoAudioClip _audio;
		// 文本
		std::string _text;
		AVFormatContext* _formatContext;
		// 是否初始化ffm
		static bool s_bInitFFmpeg;
	};
}