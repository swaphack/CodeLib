#pragma once

#include "macros.h"

namespace render
{
	// 2dͼƬ 
	// Ĭ����ʱ�����
	class CtrlImage : public ColorNode
	{
	public:
		CtrlImage();
		virtual ~CtrlImage();
	public:
		virtual void draw();

		// ����ͼƬ·��
		void setImagePath(const char* path, ImageFormat format = EIF_PNG);
		// ����ͼƬ����
		void setTexture(const Texture* texture);
		// ����Ҫ��ʾ����������
		void setTexRect(sys::Rect rect);
		// ����ͼƬ����֡
		void setTexFrame(const TexFrame* texFrame);
		// ��ȡ����֡
		const TexFrame* getTexFrame();
		// ����ˮƽ��ת
		void setFlipX(bool status);
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		bool isFlipY();
	protected:
		virtual void initSelf();
	protected:
		// ͼƬ�ṹ
		Ctrl_ImageDefine _imageDefine;
		// ����֡
		TexFrame _texFrame;
		// ��������
		TextureRect _texRect;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX;
		// �Ƿ�ֱ��ת
		bool _bFlipY;
	};
}