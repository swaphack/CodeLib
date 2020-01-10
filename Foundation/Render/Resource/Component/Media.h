#pragma once

#include "system.h"
#include "Image.h"
#include "Audio.h"
#include <map>

namespace render
{
	// 媒体帧长度类型
	typedef float mf_s;

	// 媒体库
	class Media
	{
	public:
		Media();
		virtual ~Media();
	public:
		// 自动跳转到下一帧
		virtual void autoNextFrame();
		// 获取下一帧视频图片
		virtual Image* getNextPicture();

		// 获取下一帧音频
		virtual Audio* getNextAudio();

		// 获取下一帧标题
		virtual std::string getNextTitle();

		// 设置视频帧位置
		virtual void setVideoFrame(mf_s frame);

		// 获取媒体宽度
		uint32_t getWidth() const;
		// 获取媒体高度
		uint32_t getHeight() const;
		// 获取媒体帧率
		float getFrameRate() const;
		// 获取时长
		float getTime() const;
	protected:
		// 设置媒体宽度
		void setWidth(uint32_t val);
		// 设置媒体高度
		void setHeight(uint32_t val);
		// 设置媒体帧率
		void setFrameRate(float val);
		// 设置时长
		void setTime(float val);
		// 加载视频数据
		virtual Image* loadVideoFrame(mf_s frame_time) { return nullptr; }
		// 加载音频数据
		virtual Audio* loadAudioFrame(mf_s frame_time) { return nullptr; }
	private:
		// 帧率
		float _frameRate;
		// 媒体宽度
		uint32_t _width;
		// 媒体高度
		uint32_t _height;
		// 时长
		float _time;
	};
}