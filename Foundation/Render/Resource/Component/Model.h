#pragma once

#include "system.h"

namespace render
{
	// 模型资源格式
	enum ModelResourceFormat
	{
		EMRF_NONE,
		EMRF_3DS,	// 3ds
	};

	// 3d模型
	class Model3D
	{
	public:
		Model3D();
		virtual ~Model3D();
	public:
		// 获取图像格式
		virtual ModelResourceFormat getModelFormat() { return EMRF_NONE; }

		virtual void load(const char* filename);
	protected:
	private:
	};
}