#pragma once

#include "../macros.h"

namespace render
{
	// �������������
	enum CubeFace
	{
		ECF_FRONT = 0,	// ǰ��
		ECF_BACK,		// ����
		ECF_LEFT,		// ����
		ECF_RIGHT,		// ����
		ECF_TOP,		// ����
		ECF_BOTTOM,		// ����
	};

	// 3dģ�ͻ������ռ�������
	class Cube : public CtrlModel
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual void draw();

		// ���õ��������֡
		void setFaceFrame(CubeFace face, TexFrame* frame);
		// ���������������֡
		virtual void setTexFrame(TexFrame* frame);
	protected:
		virtual void initSelf();
		// ��ȡ�������
		TextureRect* getTextureRect(ModelFace face);
	private:
		// �����������
		TexFrame* _faceFrames[6];
		// ����
		sys::Vector _normal[6];
		// ��������
		TextureCube _texCube;
	};
}