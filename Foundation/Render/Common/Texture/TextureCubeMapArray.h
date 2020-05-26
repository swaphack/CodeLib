#pragma once

#include "Texture.h"

namespace render
{
	// 立方体纹理映射
	class TextureCubeMapArray : public Texture
	{
	public:
		TextureCubeMapArray();
		virtual ~TextureCubeMapArray();
	public:
		// depth 为6的倍数，因为一个立方体有六个面
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	};
}