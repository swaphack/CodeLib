#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	// 纹理基础
	class Texture : public sys::Object
	{
	public:
		Texture();
		virtual ~Texture();
	public:
		/**
		*	纹理编号
		*/
		uint32_t getTextureID() const;
		/**
		*	宽度
		*/
		int getWidth() const;
		/**
		*	宽度
		*/
		void setWidth(uint32_t val);
		/**
		*	高度
		*/
		uint32_t getHeight() const;
		/**
		*	高度
		*/
		void setHeight(uint32_t val);
		/**
		*	深度
		*/
		uint32_t getDepth() const;
		/**
		*	深度
		*/
		void setDepth(uint32_t val);
		/**
		*	纹理是否可用
		*/
		bool isEnable();
	public:
		/**
		*	根据图片数据格式，获取纹理格式
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TexImageDataFormat& format, TexImageInternalFormat& internalFormat);
	protected:
		/**
		*	创建纹理
		*/
		void initTexture();
		/**
		*	释放纹理
		*/
		void releaseTexture();
	protected:
		/**
		*	纹理编号
		*/
		uint32_t _textureID;
		/**
		*	宽度
		*/
		uint32_t _width;
		/**
		*	高度
		*/
		uint32_t _height;
		/**
		*	深度
		*/
		uint32_t _depth;
	};

	//////////////////////////////////////////////////////////////////////////

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
		virtual void load(const sys::ImageDetail* image, const TextureSetting2D& setting = TextureSetting2D());
	};
}