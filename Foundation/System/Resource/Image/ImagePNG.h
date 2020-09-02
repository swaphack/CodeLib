#pragma once

#include "IImageLoader.h"
#include "ImageDetail.h"

namespace sys
{
	/**
	*	png 格式图片
	*/
	class ImagePNG : public ImageDetail, public IImageLoader
	{
	public:
		ImagePNG();
		virtual ~ImagePNG();
	public:
		virtual bool load(const std::string& fullpath);
	private:
		// 获取纹理信息
		int setTextureInfo(int color_type);

	};
}