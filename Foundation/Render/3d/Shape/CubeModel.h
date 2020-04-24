#pragma once

#include "3d/Common/Model.h"

namespace render
{
#define CUBE_FACE_COUNT 6

	class Texture2D;

	class CubeModel : public Model
	{
	public:
		CubeModel();
		virtual ~CubeModel();
	public:
		virtual bool init();
	public:
		// 设置纹理
		void setTexture(const std::string& name, Texture2D* texture);
	protected:
		void onCubeChange();
	private:
		// 纹理
		Texture2D* _texture = nullptr;
		// 纹理坐标
		TextureCubeVertex _texCube;
	};
}