#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	tga 格式图片
	*/
	class ImageTarga : public ImageDetail, public IImageLoader
	{
	public:
		ImageTarga();
		virtual ~ImageTarga();
	public:
		virtual bool load(const std::string& fullpath);
	protected:
		// 获取纹理信息
		void setTextureInfo(int pixel_depth);
	};
}