#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	tiff��ʽͼƬ
	*/
	class ImageTIFF : public ImageDetail, public IImageLoader
	{
	public:
		ImageTIFF();
		virtual ~ImageTIFF();
	public:
		virtual bool load(const std::string& filename);
	protected:
	private:
	};
}
