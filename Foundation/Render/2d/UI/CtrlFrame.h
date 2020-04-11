#pragma once

#include "Common/Node/ColorNode.h"
#include "Common/struct/texture_common.h"

#include "mathlib.h"

namespace render
{
	class Texture;
	class TexFrame;

	// ֡ͼƬ��Ĭ����ʱ�����
	class CtrlFrame : public ColorNode
	{
	public:
		CtrlFrame();
		virtual ~CtrlFrame();
	public:
		virtual bool init();
	protected:
		virtual void drawSample();
	public:
		// ����ͼƬ����
		void setTexture(const Texture* texture);
		// ����ͼƬ����
		void setTextureWithRect(const Texture* texture);
		// ����Ҫ��ʾ����������
		void setTexRect(const math::Rect& rect);
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
		void onTextureChange();
	protected:
		// ����֡
		TexFrame* _texFrame;
		// ��������
		TextureRectVertex _texRect;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX;
		// �Ƿ�ֱ��ת
		bool _bFlipY;
	};
}