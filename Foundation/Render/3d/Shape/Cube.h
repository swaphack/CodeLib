#pragma once

#include "../Common/import.h"

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
		virtual bool init();

		virtual void draw();

		// ���õ��������֡
		void setFaceFrame(CubeFace face, TexFrame* frame);
		// ���������������֡
		virtual void setTexFrame(TexFrame* frame);
	protected:
		virtual void initSelf();
		// ��ȡ�������
		TextureRect* getTextureRect(ModelFace face);

		void onFaceFrameChange();
	private:
		// �����������
		TexFrame* _faceFrames[6];
		// ����
		sys::Vector3 _normal[6];
		// ��������
		TextureCube _texCube;
	};
}