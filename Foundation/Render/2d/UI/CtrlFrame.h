#pragma once


#include "CtrlWidget.h"

#include "mathlib.h"

namespace render
{
	class Texture2D;
	class Material;
	class Mesh;

	// ֡ͼƬ��Ĭ����ʱ�����
	class CtrlFrame : public CtrlWidget
	{
	public:
		CtrlFrame();
		virtual ~CtrlFrame();
	public:
		virtual bool init();
	public:
		// ����ͼƬ����
		void setTexture(const Texture2D* texture);
		// ����ͼƬ����
		void setTextureWithRect(const Texture2D* texture);
		// ����Ҫ��ʾ����������
		void setTexRect(const math::Rect& rect);
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
	public:
		Material* getMaterial();
		Mesh* getMesh();
	protected:
		virtual void drawSample();
	protected:
		void onTextureChange();

		void drawSampleWithClientArray();
		void drawSampleWithBufferObject();

		void initBufferObject();
		void updateBufferData();
	protected:
		// ��������
		TextureRectVertex _texRect;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX;
		// �Ƿ�ֱ��ת
		bool _bFlipY;
		// ����
		Material* _material = nullptr;
		// ����
		Mesh* _mesh = nullptr;
	};
}