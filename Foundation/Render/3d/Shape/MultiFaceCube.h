#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/texture_common.h"

namespace render
{
#define CUBE_FACE_COUNT 6

	class Texture2D;

	/**
	*	多面立方体，每个面一个mesh
	*/
	class MultiFaceCube : public Model
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	public:
		virtual bool init();
	public:
		// 设置纹理
		void setFaceTextureName(CubeFace face, const std::string& name);
	protected:
		virtual void initBufferObject();

		void onCubeChanged();
	private:
		// 坐标
		CubeVertex _cubePosition;
		// 六个面的顶点信息
		RectVertex _faces[CUBE_FACE_COUNT];
	};
}