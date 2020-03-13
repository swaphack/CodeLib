#pragma once

#include "CubeModel.h"

namespace render
{
	// 3d模型基础，空间立方体,多面
	class MultiFaceCube : public CubeModel
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	public:
		virtual bool init();

		virtual void draw();
	public:
		// 设置单面的纹理帧
		void setFaceFrame(ModelFace face, TexFrame* frame);
		// 设置所有面的纹理帧
		void setAllFaceFrame(TexFrame* frame);
		// 设置所有面的材质
		void setAllFaceMaterial(Material* mat);
	protected:
		virtual void onCubeChange();
	private:
		// 六个面的纹理
		TexFrame* _faceFrames[6];
		// 法线
		math::Vector3 _normal[6];
		// 纹理坐标
		TextureCube _texCube;
	};
}