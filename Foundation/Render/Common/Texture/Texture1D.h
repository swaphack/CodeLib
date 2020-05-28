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
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int width, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	public:
		/**
		*	����ѹ��
		*/
		void compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int imageSize, const void* data);
		/**
		*	����ѹ��
		*/
		void compressedTextureSubImage(int level, int xoffset, int width, TextureCompressedInternalFormat format, int imageSize, const void* data);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data);
	};
}