#pragma once

#include <math.h>
#include "IModelLoader.h"
#include "ModelDetail.h"

namespace sys
{
	class ModelDetail3DS : public ModelDetail, public IModelLoader
	{
	public:
		ModelDetail3DS();								// 初始化数据成员
		virtual ~ModelDetail3DS();
	public:
		virtual bool load(const std::string& fullpath);
	};
}