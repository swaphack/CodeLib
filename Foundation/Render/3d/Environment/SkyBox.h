#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class TextureCubeMap;
	/**
	*	天空盒
	*	还有问题
	*/
	class SkyBox : public Model
	{
	public:
		SkyBox();
		virtual ~SkyBox();
	public:
		virtual bool init();
	public:
		void setFaceImage(CubeFace face, const std::string& filepath);
	protected:
		virtual void beforeDrawNode();
		virtual void afterDrawNode();
	protected:
		void onImageChanged();
		void onSpaceChanged();
	private:
		// 坐标
		CubeVertex _cubePosition;
		// 纹理
		TextureCubeMap* _texCubeMap = nullptr;

		std::string _imagePaths[6];
	};
}