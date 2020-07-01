#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class Texture2D;
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
	protected:
		void onSpaceChanged();
	private:
		// 坐标
		CubeVertex _cubePosition;
		// 纹理
		Texture2D* _tex2d = nullptr;
	};
}