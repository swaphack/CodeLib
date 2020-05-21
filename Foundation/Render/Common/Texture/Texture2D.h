#pragma once

#include "Texture.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	struct TextureSetting2D
	{
		TextureMinFilter minFilter = TextureMinFilter::LINEAR;
		TextureMagFilter magFilter = TextureMagFilter::LINEAR;
		TextureWrapMode wrapS = TextureWrapMode::CLAMP;
		TextureWrapMode wrapT = TextureWrapMode::CLAMP;
	};

	// 2d纹理
	class Texture2D : public Texture
	{
	public:
		Texture2D();
		virtual ~Texture2D();
	public:
		/**
		*	分配纹理缓存
		*/
		void setTextureStorage(int levels, TextureInternalFormat internalFormat, int width, int height);
		/**
		*	设置纹理数据
		*/
		void setTextureSubImage(int level, int xoffset, int yoffset, int width, int height, TextureDataFormat format, TextureDataType type, const void* pixels);
	public:
		/**
		*	设置纹理
		*/
		void setTextureImage(int level, TextureInternalFormat internalFormat, int width, int height, int border, TextureDataFormat format, TextureDataType type, const void* data);
	public:
		virtual void load(const sys::ImageDetail* image, const TextureSetting2D& setting = TextureSetting2D());
	};
}
