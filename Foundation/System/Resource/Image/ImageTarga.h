#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	tga ��ʽͼƬ
	*/
	class ImageTarga : public ImageDetail, public IImageLoader
	{
	public:
		ImageTarga();
		virtual ~ImageTarga();
	public:
		virtual bool load(const std::string& fullpath);
	protected:
		// ��ȡ������Ϣ
		void setTextureInfo(int pixel_depth);
	};
}