#pragma once

#include "CtrlAnimation.h"
#include "Resource/Config/MediaDefine.h"

namespace render
{
	class Texture2D;
	class MediaDetail;
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
		void setMediaURL(const std::string& url, bool defaultSize = true);
	protected:
		// ��ȡ��һ�������֡
		Texture2D* getNextTexture();
	private:
		// ý�����ݽṹ
		MediaDefine _mediaDefine;
		// ý������
		MediaDetail* _media;
		// ��Ч
		CtrlAudioSourceClip* _ctrlAudio;
	};
}