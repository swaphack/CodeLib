#pragma once

#include "macros.h"

namespace render
{
	// Ĭ����ʱ�����
	class CtrlFrame : public ColorNode
	{
	public:
		CtrlFrame();
		virtual ~CtrlFrame();
	public:
		virtual void draw();

		// ����ͼƬ����
		void setTexture(const Texture* texture);
		// ����ͼƬ����
		void setTextureWithRect(const Texture* texture);
		// ����Ҫ��ʾ����������
		void setTexRect(const sys::Rect& rect);
		// ����ͼƬ����֡
		void setTexFrame(const TexFrame* texFrame);
		// ��ȡ����֡
		const TexFrame* getTexFrame();
		// ����ˮƽ��ת
		void setFlipX(bool status);
		// �Ƿ�ˮƽ��ת
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		// �Ƿ�ֱ��ת
		bool isFlipY();
		// �Ƿ�˳ʱ��
		bool isCounter();
		// �����Ƿ�˳ʱ��
		void setCounter(bool status);
	protected:
		virtual void initSelf();
	protected:
		// ����֡
		TexFrame* _texFrame;
		// ��������
		TextureRect _texRect;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX;
		// �Ƿ�ֱ��ת
		bool _bFlipY;
		// ���������Ƿ�˳ʱ��
		bool _bCounter;
	};
}