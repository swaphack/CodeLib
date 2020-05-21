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
		Texture(TextureTarget target);
		virtual ~Texture();
	public:
		/**
		*	纹理编号
		*/
		uint32_t getTextureID() const;
		/**
		*	纹理类型
		*/
		TextureTarget getTextureTarget();
	public:
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
	public:
		/**
		*	纹理是否可用
		*/
		bool isValid();
		/**
		*	绑定纹理
		*/
		void bindTexture();
		/**
		*	绑定纹理
		*/
		void unbindTexture();
		/**
		*	绑定纹理单元
		*/
		void bindTextureUnit(uint32_t unit);
	public:
		/**
		*	获取纹理数据
		*/
		void getTextureImage(int level, TextureDataFormat format, TextureDataType type, int size, void* pixels);
	public:
		/**
		*	根据图片数据格式，获取纹理格式
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TextureDataFormat& format, TextureInternalFormat& internalFormat);
		/**
		*	根据图片数据格式，获取纹理格式
		*/
		static void getStorageTextureFormat(sys::ImageDataFormat imgFormat, TextureDataFormat& format, TextureInternalFormat& internalFormat);
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
		uint32_t _textureID = 0;
		/**
		*	纹理类型
		*/
		TextureTarget _textureTarget = TextureTarget::NONE;
		/**
		*	宽度
		*/
		uint32_t _width = 0;
		/**
		*	高度
		*/
		uint32_t _height = 0;
		/**
		*	深度
		*/
		uint32_t _depth = 0;
	};
}