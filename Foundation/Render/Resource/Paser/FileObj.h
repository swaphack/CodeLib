#pragma once

#include <math.h>
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Loader/IResourceLoader.h"

namespace render
{
	class FileObj : public ModelDetail, public IResourceLoader
	{
	public:
		FileObj();								
		virtual ~FileObj();
	public:
		virtual void load(const std::string& filename);
	};
}