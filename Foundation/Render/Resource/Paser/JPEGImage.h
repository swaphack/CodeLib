#pragma once

#include "macros.h"

namespace render
{
	class JPEGImage : public ImageDetail, public IResourceLoader
	{
	public:
		JPEGImage();
		virtual ~JPEGImage();
	public:
		virtual void load(const char* filename);
	};
}