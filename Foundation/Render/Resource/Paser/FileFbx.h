#pragma once

#include <math.h>
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Loader/IResourceLoader.h"

namespace render
{
	class FileFbx : public ModelDetail, public IResourceLoader
	{
	public:
		FileFbx();
		virtual ~FileFbx();
	public:
		virtual bool load(const std::string& filename);
	};
}