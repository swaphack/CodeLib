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
		// depth 为6的倍数，因为一个立方体有六个面
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth);
	};
}