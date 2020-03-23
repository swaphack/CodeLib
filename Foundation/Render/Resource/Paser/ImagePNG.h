#pragma once

#include "macros.h"

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
		void setTextureInfo(int color_type);
	};
}