#pragma once

#include "system.h"
#include <map>

namespace render
{
	// ý��֡��������
	typedef float mf_s;

	class ImageDetail;
	class AudioDetail;

	// ý���
	class MediaDetail
	{
	public:
		MediaDetail();
		virtual ~MediaDetail();
	public:
		// �Զ���ת����һ֡
		virtual void autoNextFrame();
		// ��ȡ��һ֡��ƵͼƬ
		virtual ImageDetail* getNextPicture();

		// ��ȡ��һ֡��Ƶ
		virtual AudioDetail* getNextAudio();

		// ��ȡ��һ֡����
		virtual std::string getNextTitle();

		// ������Ƶ֡λ��
		virtual void setVideoFrame(mf_s frame);

		// ��ȡý����
		uint32_t getWidth() const;
		// ��ȡý��߶�
		uint32_t getHeight() const;
		// ��ȡý��֡��
		float getFrameRate() const;
		// ��ȡʱ��
		float getTime() const;
	protected:
		// ����ý����
		void setWidth(uint32_t val);
		// ����ý��߶�
		void setHeight(uint32_t val);
		// ����ý��֡��
		void setFrameRate(float val);
		// ����ʱ��
		void setTime(float val);
		// ������Ƶ����
		virtual ImageDetail* loadVideoFrame(mf_s frame_time) { return nullptr; }
		// ������Ƶ����
		virtual AudioDetail* loadAudioFrame(mf_s frame_time) { return nullptr; }
	private:
		// ֡��
		float _frameRate;
		// ý����
		uint32_t _width;
		// ý��߶�
		uint32_t _height;
		// ʱ��
		float _time;
	};
}