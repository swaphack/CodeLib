#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	jpeg ��ʽͼƬ
	*/
	class ImageJPEG : public ImageDetail, public IImageLoader
	{
	public:
		ImageJPEG();
		virtual ~ImageJPEG();
	public:
		virtual bool load(const std::string& fullpath);
	};
}