#pragma once

#include "Resource/Loader/IMediaLoader.h"
#include "Resource/Detail/ImageDetail.h"
#include "Resource/Detail/AudioDetail.h"
#include "Resource/Detail/MediaDetail.h"

#include "Resource/Config/MediaDefine.h"

struct AVFormatContext;

namespace render
{
	// 视频图片帧
	class VideoFrameImage : public ImageDetail
	{
	public:
		VideoFrameImage();
		virtual ~VideoFrameImage();
	public:
		void init(TexImageDataFormat format, TexImageInternalFormat internalFormat, uint8_t* pixels, uint32_t width, uint32_t height, int nUnitSize);
	protected:
	private:
	};

	// 音频片段
	class VideoAudioClip : public AudioDetail
	{
	public:
		VideoAudioClip();
		VideoAudioClip(const VideoAudioClip& detail);
		virtual ~VideoAudioClip();
	public:
		void init(uint8_t* data, int frameSize);
		void init(uint8_t* data, int frameSize, int channels, int64_t channelLayout, int format, int frequency, int samples);
	};

	// ffmpeg 解析
	class MediaFFmpeg : public MediaDetail, public IMediaLoader
	{
	public:
		MediaFFmpeg();
		virtual ~MediaFFmpeg();
	public:
		// 加载视频
		virtual void load(const MediaDefine& mediaDefine);
		// 获取下一帧视频
		virtual ImageDetail* getNextPicture();
		// 获取下一帧音频图片
		virtual AudioDetail* getNextAudio();
		// 获取下一帧标题
		virtual std::string getNextTitle();
		// 自动跳转到下一帧
		virtual void autoNextFrame();
		// 设置视频帧位置
		virtual void setVideoFrame(mf_s frame);
	protected:
		// 加载ffm
		void loadFFM(const MediaDefine& mediaDefine);
		// 从本地加载
		bool loadFromLocalFile(const std::string& path);
		// 从网络上下载
		bool loadFromRemoteUrl(const std::string& path);
		// 卸载ffm
		void disposeFormatContext();
		// 获取文件中不同资源所在的位置
		void getStreamIndex(int type, int& streamIndex);
	private:
		// 视频流位置
		int _videoStream = -1;
		// 音频流位置
		int _audioStream = -1;
		// 标题流位置
		int _subTitleStream = -1;
		// 图片
		VideoFrameImage _image;
		// 音频
		VideoAudioClip _audio;
		// 文本
		std::string _text;
		/// 格式上下文
		AVFormatContext* _formatContext = nullptr;
		// 是否初始化ffm
		static bool s_bInitFFmpeg;
	};
}