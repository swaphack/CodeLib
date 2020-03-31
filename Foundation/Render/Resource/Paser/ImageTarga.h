#pragma once

#include "Resource/Loader/IResourceLoader.h"
#include "Resource/Detail/ImageDetail.h"

namespace render
{
	/**
	*	tga ��ʽͼƬ
	*/
	class ImageTarga : public ImageDetail, public IResourceLoader
	{
	public:
		ImageTarga();
		virtual ~ImageTarga();
	public:
		virtual void load(const std::string& filename);
	protected:
		// ��ȡ������Ϣ
		void setTextureInfo(int pixel_depth);
	};
}