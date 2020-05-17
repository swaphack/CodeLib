#pragma once

#include "Framework/Object.h"
#include <map>
#include <string>
namespace sys
{
	class ImageDetail;
	class AudioDetail;

	// ý���
	class MediaDetail : public Object
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
		virtual void setVideoFrame(float frame);

		// ��ȡý�����
		uint32_t getWidth() const;
		// ��ȡý��߶�
		uint32_t getHeight() const;
		// ��ȡý��֡��
		float getFrameRate() const;
		// ��ȡʱ��
		float getTime() const;
	protected:
		// ����ý�����
		void setWidth(uint32_t val);
		// ����ý��߶�
		void setHeight(uint32_t val);
		// ����ý��֡��
		void setFrameRate(float val);
		// ����ʱ��
		void setTime(float val);
		// ������Ƶ����
		virtual ImageDetail* loadVideoFrame(float frame_time) { return nullptr; }
		// ������Ƶ����
		virtual AudioDetail* loadAudioFrame(float frame_time) { return nullptr; }
	private:
		// ֡��
		float _frameRate;
		// ý�����
		uint32_t _width;
		// ý��߶�
		uint32_t _height;
		// ʱ��
		float _time;
	};
}