#pragma once

#include "CtrlAnimation.h"

namespace sys
{
	class MediaDetail;
}

namespace render
{
	class Texture2D;
	class CtrlAudioSourceClip;

	// ý�壨����ͼ���������
	class CtrlMedia : public CtrlAnimation
	{
	public:
		CtrlMedia();
		virtual ~CtrlMedia();
	public:
		virtual bool init();

		virtual void draw();
	public:
		// ��ʼ
		virtual void start();
		// �ָ�
		virtual void pause();
		// ��ͣ
		virtual void resume();
		// ����
		virtual void stop();
	public:
		// ����ý���ļ�
		void loadFromURL(const std::string& url, bool defaultSize = true);
	protected:
		// ��ȡ��һ�������֡
		Texture2D* getNextTexture();
	private:
		// ý�����ݽṹ
		std::string _filepath;
		// ý������
		sys::MediaDetail* _media;
		// ��Ч
		CtrlAudioSourceClip* _ctrlAudio;
	};
}