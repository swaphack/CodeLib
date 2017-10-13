#pragma once

#include "../Common/import.h"

namespace render
{
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
		TextureRect* getTextureRect(ModelFace index);

		void onCubeChange();
	private:
		// �����������
		TexFrame* _faceFrames[6];
		// ����
		sys::Vector3 _normal[6];
		// ��������
		TextureCube _texCube;
	};
}