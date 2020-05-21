#pragma once

#include "Texture.h"

namespace render
{
	// 1d����
	class Texture1D : public Texture
	{
	public:
		Texture1D();
		virtual ~Texture1D();
	public:
		/**
		*	����������
		*/
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int width, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int border, TextureDataFormat format, TextureDataType type, const void* data);
	};
}