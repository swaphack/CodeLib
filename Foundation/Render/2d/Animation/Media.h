#pragma once

#include "Animation.h"

namespace sys
{
	class MediaDetail;
}

namespace render
{
	class Texture2D;
	class DrawTexture2D;
	class CtrlAudioSourceClip;

	// ý�壨����ͼ���������
	class Media : public Animation
	{
	public:
		Media();
		virtual ~Media();
	public:
		virtual bool init();
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
		DrawTexture2D* _drawNode = nullptr;
	};
}