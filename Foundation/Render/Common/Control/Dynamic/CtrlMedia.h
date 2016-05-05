#pragma once

#include "macros.h"
#include <map>

namespace render
{
	// ý�壨����ͼ���������
	class CtrlMedia : public Animation
	{
	public:
		CtrlMedia();
		virtual ~CtrlMedia();
	public:
		virtual void draw();

		// ����ý���ļ�
		virtual void setMediaPath(const char* path);
		// ���õ�ǰ֡
		void setFrame(int frame);
		// ��ȡ��ǰ֡
		int getFrame();
	protected:
		// ���¼������
		virtual void initSelf();
		// ��ʱ�����¼�
		virtual void updateSelf(float interval);
		// ��ȡ��һ�������֡
		Texture2D* getNextTexture();
		// �Ƴ���������
		void removeAllTextures();
	private:
		// ý�����ݽṹ
		MediaDefine _mediaDefine;
		// ý������
		Media* _media;
		// ֡������ {֡�� ����}
		std::map<mf_s, Texture2D*> _texures;
		// ��ǰ��������
		TextureRect _texRect;
		// ��ǰ����֡
		TexFrame* _texFrame;
		// ��ǰ֡
		float _frame;
	};
}