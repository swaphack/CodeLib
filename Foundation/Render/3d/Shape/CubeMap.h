#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class TextureCubeMap;

	/**
	*	立方体纹理
	*/
	class CubeMap : public Model
	{
	public:
		CubeMap();
		virtual ~CubeMap();
	public:
		virtual bool init();
	public:
		void setFaceTexture(CubeFace face, const std::string& filepath);

		void setLeftTexture(const std::string& filepath);
		void setRightTexture(const std::string& filepath);
		void setBottomTexture(const std::string& filepath);
		void setTopTexture(const std::string& filepath);
		void setFrontTexture(const std::string& filepath);
		void setBackTexture(const std::string& filepath);
	protected:
		void onImageChanged();
		virtual void onCubeChanged();
	protected:
		// 坐标
		CubeVertex _cubePosition;
		// 纹理
		TextureCubeMap* _texCubeMap = nullptr;

		std::string _imagePaths[6];
	};
}