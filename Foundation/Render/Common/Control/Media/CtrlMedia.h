#pragma once

#include "../Dynamic/CtrlAnimation.h"

namespace render
{
	// ý�壨����ͼ���������
	class CtrlMedia : public CtrlAnimation
	{
	public:
		CtrlMedia();
		virtual ~CtrlMedia();
	public:
		virtual bool init();

		virtual void draw();

		// ��ʼ
		virtual void start();
		// �ָ�
		virtual void pause();
		// ��ͣ
		virtual void resume();
		// ����
		virtual void stop();

		// ����ý���ļ�
		void setMediaPath(const char* path, bool defaultSize = true);
	protected:
		// ���¼������
		virtual void initSelf();
		// ��ȡ��һ�������֡
		Texture2D* getNextTexture();
	private:
		// ý�����ݽṹ
		MediaDefine _mediaDefine;
		// ý������
		Media* _media;
	};
}