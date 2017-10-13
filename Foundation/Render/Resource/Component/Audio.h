#pragma once

#include "system.h"

namespace render
{
	// ��Ƶ
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
		int getFrequency();
		int getSize();
		int getSamples();
	protected:
		void setData(uchar* data);
		void setChannels(int channels);
		void setChannelLayout(int64_t channelLayout);
		void setFormat(int format);
		void setFrequency(int frequency);
		void setSize(int size);
		void setSamples(int samples);
	private:
		// ����
		uchar* _data;
		// ��С
		int _size;
		// ͨ����
		int _channels;
		// ͨ������
		int64_t _channelLayout;
		// ��ʽ
		int _format;
		// ����Ƶ��
		int _frequency;
		// ������
		int _samples;
	};
}