#pragma once

#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ImageDetail.h"

namespace render
{
	/**
	*	png 格式图片
	*/
	class ImagePNG : public ImageDetail, public IResourceLoader
	{
	public:
		ImagePNG();
		virtual ~ImagePNG();
	public:
		virtual void load(const std::string& filename);
	private:
		// 获取纹理信息
		int setTextureInfo(int color_type);
	};
}