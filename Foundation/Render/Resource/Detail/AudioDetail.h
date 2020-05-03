#pragma once

#include "system.h"

namespace render
{
	// ��Ƶ
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
		// ����
		sys::MemoryData _data;
		// ͨ����
		int _channels = 0;
		// ͨ������
		int64_t _channelLayout = 0;
		// ��ʽ
		int _format = 0;
		// ����Ƶ��
		int _frequency = 0;
		// ������
		int _samples = 0;
	};
}