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
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int width, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	public:
		/**
		*	纹理压缩
		*/
		void compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int imageSize, const void* data);
		/**
		*	纹理压缩
		*/
		void compressedTextureSubImage(int level, int xoffset, int width, TextureCompressedInternalFormat format, int imageSize, const void* data);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data);
	};
}