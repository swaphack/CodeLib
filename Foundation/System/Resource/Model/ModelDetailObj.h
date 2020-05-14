#pragma once

#include <math.h>
#include "IModelLoader.h"
#include "ModelDetail.h"

namespace sys
{
	class ModelDetailObj : public ModelDetail, public IModelLoader
	{
	public:
		ModelDetailObj();								
		virtual ~ModelDetailObj();
	public:
		virtual bool load(const std::string& filename);
	};
}