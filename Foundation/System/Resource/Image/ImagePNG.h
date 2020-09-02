#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	png ��ʽͼƬ
	*/
	class ImagePNG : public ImageDetail, public IImageLoader
	{
	public:
		ImagePNG();
		virtual ~ImagePNG();
	public:
		virtual bool load(const std::string& fullpath);
	private:
		// ��ȡ������Ϣ
		int setTextureInfo(int color_type);

	};
}