#pragma once


#include "Texture.h"

namespace render
{
	// 2d��������
	class Texture2DArray : public Texture
	{
	public:
		Texture2DArray();
		virtual ~Texture2DArray();
	public:
		/**
		*	����������
		*/
		void setTextureStorage(int levels, TextureInternalSizedFormat internalFormat, int width, int height, int depth);
		/**
		*	������������
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureExternalFormat format, TextureExternalDataType type, const void* pixels);
	public:
		/**
		*	����ѹ��
		*/
		void compressedTextureImage(int level, TextureCompressedInternalFormat format, int width, int height, int depth, int imageSize, const void* data);
		/**
		*	����ѹ��
		*/
		void compressedTextureSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureCompressedInternalFormat format, int imageSize, const void* data);
	public:
		/**
		*	��������
		*/
		void setTextureImage(int level, TextureInternalSizedFormat internalFormat, int width, int height, int depth, int border, TextureExternalFormat format, TextureExternalDataType type, const void* data);
	};
}