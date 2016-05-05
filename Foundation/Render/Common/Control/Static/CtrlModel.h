#pragma once

#include "macros.h"

namespace render
{
	// 3dģ��
	class CtrlModel : public ColorNode
	{
	public:
		CtrlModel();
		virtual ~CtrlModel();
	public:
		virtual void draw();
		// ����ģ�Ͳ���
		void setMatrial(Material* material);
		// ��ȡģ�Ͳ���
		Material* getMatrial();
		// ���õ��������֡
		void setFaceFrame(ModelFace face, TexFrame* frame);
		// ���������������֡
		void setAllFacesFrame(TexFrame* frame);
	protected:
		virtual void initSelf();
		// ��ȡ�������
		TextureRect* getTextureRect(ModelFace face);
	protected:
		// ģ�Ͳ���
		Material* _material;
		// ����
		TexFrame* _faceFrames[6];
		// ����
		sys::Vector _normal[6];
		// ��������
		TextureCube _texCube;
	};
}