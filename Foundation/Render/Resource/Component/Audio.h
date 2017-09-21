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
		// ����
		uchar* _data;
		// ��С
		int _frameSize;
		// ͨ����
		int _channels;
		// ͨ������
		int64_t _channelLayout;
		// ��ʽ
		int _format;
		// ����Ƶ��
		int _sampleRate;
	};
}