#pragma once

#include "system.h"

namespace render
{
	// 音频
	class AudioDetail
	{
	public:
		AudioDetail();
		virtual ~AudioDetail();
	public:
		uint8_t* getData();
		int getChannels();
		int64_t getChannelLayout();
		int getFormat();
		int getFrequency();
		int getSize();
		int getSamples();
	protected:
		void setData(uint8_t* data);
		void setChannels(int channels);
		void setChannelLayout(int64_t channelLayout);
		void setFormat(int format);
		void setFrequency(int frequency);
		void setSize(int size);
		void setSamples(int samples);
	private:
		// 数据
		uint8_t* _data;
		// 大小
		int _size;
		// 通道数
		int _channels;
		// 通道布局
		int64_t _channelLayout;
		// 格式
		int _format;
		// 采样频率
		int _frequency;
		// 采样数
		int _samples;
	};
}