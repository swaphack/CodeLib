#pragma once

#include "Texture.h"

namespace render
{
	// 立方体纹理映射 与二位数组纹理等价
	class TextureCubeMap : public Texture
	{
	public:
		TextureCubeMap();
		virtual ~TextureCubeMap();
	public:
		void load(const sys::ImageDetail* imageDetails[6], const TextureSetting& setting = TextureSetting());
	};
}