#pragma once

#include "CtrlWidget.h"
#include "mathlib.h"
#include "Common/struct/vertex_common.h"

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
		// ����ˮƽ��ת
		void setFlipX(bool status);
		// �Ƿ�ˮƽ��ת
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		// �Ƿ�ֱ��ת
		bool isFlipY();
	protected:
		void onTextureChange();
	protected:
		// ����������Ϣ
		RectVertex _vertexes;
		// �Ƿ�ˮƽ��ת
		bool _bFlipX = false;
		// �Ƿ�ֱ��ת
		bool _bFlipY = false;
		
	};
}