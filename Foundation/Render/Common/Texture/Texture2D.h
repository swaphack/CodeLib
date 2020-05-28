#pragma once

#include "Texture.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	// 2d����
	class Texture2D : public Texture
	{
	public:
		Texture2D();
		virtual ~Texture2D();
	public:
		/**
		*	����������
		*/
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	public:
		/**
		*	����ѹ��
		*/
		void compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int imageSize, const void* data);
		/**
		*	����ѹ��
		*/
		void compressedTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureCompressedInternalFormat format, int imageSize, const void* data);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int height, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data);
	public:
		virtual void load(const sys::ImageDetail* image, const TextureSetting& setting = TextureSetting());
	};
}
