#pragma once

#include "Texture.h"

namespace render
{
	// 3d����
	class Texture3D : public Texture
	{
	public:
		Texture3D();
		virtual ~Texture3D();
	public:
		/**
		*	����������
		*/
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height, int depth);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int depth, int border, TextureDataFormat format, TextureDataType type, const void* data);
	};
}