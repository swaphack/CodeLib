#pragma once

#include "Texture.h"

namespace render
{
	// 1d��������
	class Texture1DArray : public Texture
	{
	public:
		Texture1DArray();
		virtual ~Texture1DArray();
	public:
		/**
		*	����������
		*/
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int border, TextureDataFormat format, TextureDataType type, const void* data);
	};
}