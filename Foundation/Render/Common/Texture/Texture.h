#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	class TextureSetting
	{
	public:
		// 纹理单元 ActiveTextureName::TEXTURE0 + unit
		TextureMinFilter minFilter = TextureMinFilter::LINEAR;
		TextureMagFilter magFilter = TextureMagFilter::LINEAR;
		TextureWrapMode wrapS = TextureWrapMode::CLAMP;
		TextureWrapMode wrapT = TextureWrapMode::CLAMP;
	};

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
		*	设置参数
		*/
		void setTexParameter(TextureParameter name, int value);
		/**
		*	设置参数
		*/
		void setTexParameter(TextureParameter name, float value);
		/**
		*	设置参数
		*/
		void setTexParameter(TextureParameter name, const int* value);
		/**
		*	设置参数
		*/
		void setTexParameter(TextureParameter name, const float* value);
	public:
		/**
		*	纹理是否可用
		*/
		bool isValid() const;
		/**
		*	绑定纹理
		*/
		void bindTexture();
		/**
		*	绑定纹理
		*/
		void unbindTexture();
		/**
		*	启用
		*/
		void activeTexture(ActiveTextureName unit);
		/**
		*	绑定纹理单元
		*	等价
		*	activeTexture(ActiveTextureName::TEXTURE0 + unit);
		*	bindTexture();
		*/
		void bindTextureUnit(uint32_t unit);
		/**
		*	应用配置
		*/
		void apply(const TextureSetting& setting);
	public:
		/**
		*	获取纹理数据
		*/
		void getTextureImage(int level, TextureExternalFormat format, TextureExternalDataType type, int size, void* pixels);
	public:
		/**
		*	根据图片数据格式，获取纹理格式
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TextureExternalFormat& format, TextureInternalBaseFormat& internalFormat, int& size);
		/**
		*	根据图片数据格式，获取纹理格式
		*/
		static void getStorageTextureFormat(sys::ImageDataFormat imgFormat, TextureExternalFormat& format, TextureInternalSizedFormat& internalFormat, int& size);
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