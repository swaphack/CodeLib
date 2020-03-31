#pragma once

#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ImageDetail.h"

namespace render
{
	/**
	*	jpeg ��ʽͼƬ
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