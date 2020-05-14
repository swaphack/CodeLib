#pragma once

#include <math.h>
#include "IModelLoader.h"
#include "ModelDetail.h"

namespace sys
{
	class ModelDetailFbx : public ModelDetail, public IModelLoader
	{
	public:
		ModelDetailFbx();
		virtual ~ModelDetailFbx();
	public:
		virtual bool load(const std::string& fullpath);
	};
}