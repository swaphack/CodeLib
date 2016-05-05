#pragma once

#include "system.h"

namespace render
{
	// 模型工具 3d
	class ModelTool
	{
	public:
		// 将屏幕体积转为opengl坐标
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
	};
}