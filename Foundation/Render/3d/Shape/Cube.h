#pragma once

#include "../Common/import.h"

namespace render
{
	//---------------------ö��---------------------
	// ������
	enum ModelFace
	{
		EMF_FRONT,		// ǰ��
		EMF_BACK,		// ����
		EMF_LEFT,		// ����
		EMF_RIGHT,		// ����
		EMF_TOP,		// ����
		EMF_BOTTOM,		// ����
	};

	// 3dģ�ͻ������ռ�������
	class Cube : public Model
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual bool init();

		virtual void draw();

		// ���õ��������֡
		void setFaceFrame(ModelFace face, TexFrame* frame);
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