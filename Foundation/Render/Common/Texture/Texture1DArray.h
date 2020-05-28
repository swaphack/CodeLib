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
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	public:
		/**
		*	纹理压缩
		*/
		void compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int imageSize, const void* data);
		/**
		*	纹理压缩
		*/
		void compressedTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureCompressedInternalFormat format, int imageSize, const void* data);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int height, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data);
	};
}