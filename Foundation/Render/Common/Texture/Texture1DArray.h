#pragma once

#include "Texture.h"

namespace render
{
	// 1d纹理数组
	class Texture1DArray : public Texture
	{
	public:
		Texture1DArray();
		virtual ~Texture1DArray();
	public:
		/**
		*	分配纹理缓存
		*/
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int border, TextureDataFormat format, TextureDataType type, const void* data);
	};
}