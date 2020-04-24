#pragma once

#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ImageDetail.h"

namespace render
{
	/**
	*	png ��ʽͼƬ
	*/
	class ImagePNG : public ImageDetail, public IResourceLoader
	{
	public:
		ImagePNG();
		virtual ~ImagePNG();
	public:
		virtual void load(const std::string& filename);
	private:
		// ��ȡ������Ϣ
		int setTextureInfo(int color_type);
	};
}