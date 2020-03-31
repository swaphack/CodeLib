#pragma once

#include <math.h>
#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ModelDetail.h"

namespace render
{
	class File3DS : public ModelDetail, public IResourceLoader
	{
	public:
		File3DS();								// 初始化数据成员
		virtual ~File3DS();
	public:
		virtual void load(const std::string& filename);
	};
}