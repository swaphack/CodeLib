#pragma once

#include "system.h"

namespace render
{
	// ģ�͹��� 3d
	class ModelTool
	{
	public:
		// ����Ļ���תΪopengl����
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
	};
}