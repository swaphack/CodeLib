#pragma once

#include "system.h"
#include "Image.h"
#include "Audio.h"
#include <map>

namespace render
{
	// ý��֡��������
	typedef float mf_s;

	// ý���
	class Media
	{
	public:
		Media();
		virtual ~Media();
	public:
		// �Զ���ת����һ֡
		virtual void autoNextFrame();
		// ��ȡ��һ֡��ƵͼƬ
		virtual Image* getNextPicture();

		// ��ȡ��һ֡��Ƶ
		virtual Audio* getNextAudio();

		// ��ȡ��һ֡����
		virtual std::string getNextTitle();

		// ������Ƶ֡λ��
		virtual void setVideoFrame(mf_s frame);

		// ��ȡý����
		uint32 getWidth() const;
		// ��ȡý��߶�
		uint32 getHeight() const;
		// ��ȡý��֡��
		float getFrameRate() const;
		// ��ȡʱ��
		float getTime() const;
	protected:
		// ����ý����
		void setWidth(uint32 val);
		// ����ý��߶�
		void setHeight(uint32 val);
		// ����ý��֡��
		void setFrameRate(float val);
		// ����ʱ��
		void setTime(float val);
		// ������Ƶ����
		virtual Image* loadVideoFrame(mf_s frame_time) { return nullptr; }
		// ������Ƶ����
		virtual Audio* loadAudioFrame(mf_s frame_time) { return nullptr; }
	private:
		// ֡��
		float _frameRate;
		// ý����
		uint32 _width;
		// ý��߶�
		uint32 _height;
		// ʱ��
		float _time;
	};
}