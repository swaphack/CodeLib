#pragma once

#include "CubeModel.h"

namespace render
{
	// 3dģ�ͻ������ռ�������,����
	class MultiFaceCube : public CubeModel
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	public:
		virtual bool init();

		virtual void draw();
	public:
		// ���õ��������֡
		void setFaceFrame(ModelFace face, TexFrame* frame);
		// ���������������֡
		void setAllFaceFrame(TexFrame* frame);
		// ����������Ĳ���
		void setAllFaceMaterial(Material* mat);
	protected:
		virtual void onCubeChange();
	private:
		// �����������
		TexFrame* _faceFrames[6];
		// ����
		math::Vector3 _normal[6];
		// ��������
		TextureCube _texCube;
	};
}