#pragma once

#include "system.h"

namespace render
{
	// 音频
	class Audio
	{
	public:
		Audio();
		virtual ~Audio();
	public:
		uchar* getData();
		int getChannels();
		int64_t getChannelLayout();
		int getFormat();
		int getSampleRate();
		int getFrameSize();
	protected:
		void setData(uchar* data);
		void setChannels(int channels);
		void setChannelLayout(int64_t channelLayout);
		void setFormat(int format);
		void setSampleRate(int sampleRate);
		void setFrameSize(int size);
	private:
		// 数据
		uchar* _data;
		// 大小
		int _frameSize;
		// 通道数
		int _channels;
		// 通道布局
		int64_t _channelLayout;
		// 格式
		int _format;
		// 采样频率
		int _sampleRate;
	};
}