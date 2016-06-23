#pragma once

#include "macros.h"

namespace render
{
	// png ͼƬ
	class PNGImage : public Image, public IResourceLoader
	{
	public:
		PNGImage();
		virtual ~PNGImage();
	public:
		virtual void load(const char* filename);
	private:
		// ��ȡ������Ϣ
		void setTextureInfo(int color_type);
	};
}