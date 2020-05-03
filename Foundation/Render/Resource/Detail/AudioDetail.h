#pragma once

#include "system.h"

namespace render
{
	// 音频
	class AudioDetail : public sys::Object
	{
	public:
		AudioDetail();
		AudioDetail(const AudioDetail& detail);
		virtual ~AudioDetail();
	public:
		uint8_t* getData() const;
		int getChannels() const;
		int64_t getChannelLayout() const;
		int getFormat() const;
		int getFrequency() const;
		int getSize() const;
		int getSamples() const;
	protected:
		void setData(uint8_t* data, int size);
		void setChannels(int channels);
		void setChannelLayout(int64_t channelLayout);
		void setFormat(int format);
		void setFrequency(int frequency);
		void setSamples(int samples); 
	public:
		AudioDetail& operator=(const AudioDetail& detail);
	private:
		// 数据
		sys::MemoryData _data;
		// 通道数
		int _channels = 0;
		// 通道布局
		int64_t _channelLayout = 0;
		// 格式
		int _format = 0;
		// 采样频率
		int _frequency = 0;
		// 采样数
		int _samples = 0;
	};
}