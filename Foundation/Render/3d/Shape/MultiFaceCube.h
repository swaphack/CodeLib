#pragma once

#include "3d/Common/MultiModel.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{

	class Texture2D;

	/**
	*	多面立方体，每个面一个mesh
	*/
	class MultiFaceCube : public MultiModel
	{
	public:
		MultiFaceCube();
		virtual ~MultiFaceCube();
	public:
		virtual bool init();
	public:
		// 设置纹理
		void setFaceTexture(CubeFace face, const std::string& filepath);

		void setLeftTexture(const std::string& filepath);
		void setRightTexture(const std::string& filepath);
		void setBottomTexture(const std::string& filepath);
		void setTopTexture(const std::string& filepath);
		void setFrontTexture(const std::string& filepath);
		void setBackTexture(const std::string& filepath);

		void setAllFacesTexture(const std::string& filepath);
	protected:
		virtual void initBufferObject();

		void onCubeChanged();
	private:
		// 坐标
		CubeVertex _cubePosition;
	};
}