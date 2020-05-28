#pragma once


#include "Texture.h"

namespace render
{
	// 2d纹理数组
	class Texture2DArray : public Texture
	{
	public:
		Texture2DArray();
		virtual ~Texture2DArray();
	public:
		/**
		*	分配纹理缓存
		*/
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	public:
		/**
		*	纹理压缩
		*/
		void compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int depth, int imageSize, const void* data);
		/**
		*	纹理压缩
		*/
		void compressedTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureCompressedInternalFormat format, int imageSize, const void* data);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int height, int depth, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data);
	};
}