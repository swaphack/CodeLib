#pragma once


#include "CtrlWidget.h"

#include "mathlib.h"

namespace render
{
	class Texture;
	class TexFrame;
	class Material;

	// ֡ͼƬ��Ĭ����ʱ�����
	class CtrlFrame : public CtrlWidget
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

		void drawSampleWithClientArray();
		void drawSampleWithBufferObject();

		void initBufferObject();
		void updateBufferData();
	protected:
		// ����֡
		TexFrame* _texFrame;
		// ��������
		TextureRectVertex _texRect;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX;
		// �Ƿ�ֱ��ת
		bool _bFlipY;
		// ����
		Material* _material = nullptr;
	};
}