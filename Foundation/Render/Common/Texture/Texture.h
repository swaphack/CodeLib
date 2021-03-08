#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	// 是否使用最新的纹理函数
#define USE_NEW_TEXTURE_FUNCTION true
	// 使用存储
#define USE_TEXTURE_STORAGE true

	class Sampler;

	class TextureSetting
	{
	public:
		// 纹理单元 ActiveTextureName::TEXTURE0 + unit
		TextureMinFilter minFilter = TextureMinFilter::NEAREST;
		TextureMagFilter magFilter = TextureMagFilter::NEAREST;
		TextureWrapMode wrapS = TextureWrapMode::CLAMP;
		TextureWrapMode wrapT = TextureWrapMode::CLAMP;
		TextureWrapMode wrapR = TextureWrapMode::CLAMP;
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
		*	设置参数
		*/
		void setTextureParameter(TextureParameter name, int value);
		/**
		*	设置参数
		*/
		void setTextureParameter(TextureParameter name, float value);
		/**
		*	设置参数
		*/
		void setTextureParameter(TextureParameter name, const int* value);
		/**
		*	设置参数
		*/
		void setTextureParameter(TextureParameter name, const uint32_t* value);
		/**
		*	设置参数
		*/
		void setTextureParameter(TextureParameter name, const float* value);
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
		*	启用
		*/
		void activeTexture(uint32_t unit);
		/**
		*	绑定纹理单元
		*	等价
		*	activeTexture(ActiveTextureName::TEXTURE0 + unit);
		*	bindTexture();
		*/
		void bindTextureUnit(uint32_t unit);
	public:
		/**
		*	生效
		*/
		void enableTextureWithSampler(uint32_t unit);
		/**
		*	失效
		*/
		void enableTexture(uint32_t unit);
	public:
		/**
		*	设置纹理配置
		*/
		void setTextureSetting(const TextureSetting& setting);
		/**
		*	纹理配置
		*/
		const TextureSetting& getTextureSetting() const;
		/**
		*	应用配置
		*/
		void applyTextureSettingWithSampler();
		/**
		*	应用配置
		*/
		void applyTextureSetting();
		/**
		*	应用配置
		*/
		void bindSampler(uint32_t unit);
	public:
		/**
		*	获取纹理数据
		*/
		void getTextureImage(int level, TextureExternalFormat format, TextureExternalDataType type, int size, void* pixels);
	public:
		/**
		*	生成mipmap
		*/
		void generateTextureMipMap();
		/**
		*	根据图片数据格式，获取纹理格式
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TextureExternalFormat& format, TextureInternalSizedFormat& internalFormat, int& size);
	public:
		bool getImageDetail(sys::ImageDetail& detail, TextureExternalFormat format);
	public:
		/**
		*	获取图片格式
		*/
		static bool getImageFormat(TextureExternalFormat format, int& nUnitSize, sys::ImageDataFormat& dataFormat);
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
		/**
		*	采样器
		*/
		Sampler* _sampler = nullptr;

		/**
		*	纹理配置
		*/
		TextureSetting _textureSettings;
	};
}