#pragma once

#include "macros.h"

namespace render
{
	/**
	*	jpeg ∏Ò ΩÕº∆¨
	*/
	class ImageJPEG : public ImageDetail, public IResourceLoader
	{
	public:
		ImageJPEG();
		virtual ~ImageJPEG();
	public:
		virtual void load(const std::string& filename);
	};
}