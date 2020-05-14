#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	bmp ∏Ò ΩÕº∆¨
	*/
	class ImageBMP : public ImageDetail, public IImageLoader
	{
	public:
		ImageBMP();
		virtual ~ImageBMP();
	public:
		virtual bool load(const std::string& fullpath);
	protected:
		void setTextureInfo(int pixel_depth);
	};
}