#pragma once

#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ImageDetail.h"

namespace render
{
	/**
	*	bmp ∏Ò ΩÕº∆¨
	*/
	class ImageBMP : public ImageDetail, public IResourceLoader
	{
	public:
		ImageBMP();
		virtual ~ImageBMP();
	public:
		virtual bool load(const std::string& filename);
	protected:
		void setTextureInfo(int pixel_depth);
	};
}