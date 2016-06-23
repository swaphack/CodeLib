#pragma once

#include "macros.h"

namespace render
{
	// png 图片
	class PNGImage : public Image, public IResourceLoader
	{
	public:
		PNGImage();
		virtual ~PNGImage();
	public:
		virtual void load(const char* filename);
	private:
		// 获取纹理信息
		void setTextureInfo(int color_type);
	};
}