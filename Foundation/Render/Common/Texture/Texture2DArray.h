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
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height, int depth);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int depth, int border, TextureDataFormat format, TextureDataType type, const void* data);
	};
}