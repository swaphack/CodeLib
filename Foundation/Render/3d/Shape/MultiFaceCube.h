#pragma once

#include "CubeModel.h"

namespace render
{
	class TexFrame;
	class MaterialDetail;

	// 3dģ�ͻ������ռ�������,����
	class MultiFaceCube : public CubeModel
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	protected:
		virtual void drawSample();
	public:
		// ���õ��������֡
		void setFaceFrame(ModelFace face, TexFrame* frame);
		// ���������������֡
		void setAllFaceFrame(TexFrame* frame);
		// ����������Ĳ���
		void setAllFaceMaterial(MaterialDetail* mat);
	protected:
		virtual void onCubeChange();
	private:
		// �����������
		TexFrame* _faceFrames[6];
		// ����
		math::Vector3 _normal[6];
		// ��������
		TextureCubeVertex _texCube;
	};
}