#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class TextureCubeMap;
	/**
	*	立方体，采用立方体纹理
	*/
	class Cube : public Model
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual bool init();
	public:
		void setFaceImage(CubeFace face, const std::string& fullfilepathpath);
		void setAllFacesImage(const std::string& filepath);
	protected:
		void onImageChanged();
		void onSpaceChanged();
	private:
		std::string _imagePaths[6];
		// 坐标
		CubeVertex _cubePosition;
		// 纹理
		TextureCubeMap* _texCubeMap = nullptr;
	};
}