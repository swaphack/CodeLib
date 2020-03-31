#pragma once

#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ImageDetail.h"

namespace render
{
	/**
	*	tga 格式图片
	*/
	class ImageTarga : public ImageDetail, public IResourceLoader
	{
	public:
		ImageTarga();
		virtual ~ImageTarga();
	public:
		virtual void load(const std::string& filename);
	protected:
		// 获取纹理信息
		void setTextureInfo(int pixel_depth);
	};
}