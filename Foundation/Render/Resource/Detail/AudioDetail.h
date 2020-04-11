#pragma once

#include "system.h"

namespace render
{
	// ��Ƶ
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
		// ����
		uint8_t* _data = nullptr;
		// ��С
		int _size = 0;
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