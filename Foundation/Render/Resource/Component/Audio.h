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
		// ����
		uint8* _data;
		// ��С
		int _size;
		// ͨ����
		int _channels;
		// ͨ������
		int64 _channelLayout;
		// ��ʽ
		int _format;
		// ����Ƶ��
		int _frequency;
		// ������
		int _samples;
	};
}