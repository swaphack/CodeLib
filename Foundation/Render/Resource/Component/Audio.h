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
		uint8* getData();
		int getChannels();
		int64 getChannelLayout();
		int getFormat();
		int getFrequency();
		int getSize();
		int getSamples();
	protected:
		void setData(uint8* data);
		void setChannels(int channels);
		void setChannelLayout(int64 channelLayout);
		void setFormat(int format);
		void setFrequency(int frequency);
		void setSize(int size);
		void setSamples(int samples);
	private:
		// 数据
		uint8* _data;
		// 大小
		int _size;
		// 通道数
		int _channels;
		// 通道布局
		int64 _channelLayout;
		// 格式
		int _format;
		// 采样频率
		int _frequency;
		// 采样数
		int _samples;
	};
}