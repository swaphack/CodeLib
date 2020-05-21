#pragma once

#include "Texture.h"

namespace render
{
	// 1d纹理
	class Texture1D : public Texture
	{
	public:
		Texture1D();
		virtual ~Texture1D();
	public:
		/**
		*	分配纹理缓存
		*/
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int width, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int border, TextureDataFormat format, TextureDataType type, const void* data);
	};
}