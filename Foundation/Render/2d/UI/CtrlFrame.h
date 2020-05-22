#pragma once

#include "CtrlWidget.h"
#include "mathlib.h"
#include "Common/struct/texture_common.h"

namespace render
{
	class Texture2D;
	class Materials;
	class Meshes;

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
	public:
		Materials* getMaterials();
		Meshes* getMeshes();
	protected:
		void onTextureChange();

		virtual void initBufferObject();
		virtual void updateBufferData();
	protected:
		// ��������
		TextureRectVertex _texRect;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX = false;
		// �Ƿ�ֱ��ת
		bool _bFlipY = false;
		
	};
}