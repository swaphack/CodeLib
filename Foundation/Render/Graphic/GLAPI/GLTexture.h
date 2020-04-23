#pragma once

#include <cstdint>

#include "macros.h"

namespace render
{
	/**
	*	纹理
	*/
	class GLTexture
	{
	public:
		static uint32_t genTexture();
		static void genTextures(int count, uint32_t* textureIDs);
		static void deleteTexture(uint32_t textureID);
		static void deleteTextures(int count, uint32_t* textureIDs);
	public:
		static void bindTexture(TextureTarget type, uint32_t textureID);
		static void bindTexture1D(uint32_t textureID);
		static void bindTexture2D(uint32_t textureID);
	public:
		static void setTexParameter(TextureTarget type, TextureParameterName paramType, int paramValue);
		/**
		*	纹理缩小
		*/
		static void setTexParameterMinFilter2D(TextureMinFilter paramValue);
		/**
		*	纹理放大
		*/
		static void setTexParameterMagFilter2D(TextureMagFilter paramValue);
		/**
		*	环绕方式
		*/
		static void setTexParameterWrapS2D(TextureWrapMode paramValue);
		/**
		*	环绕方式
		*/
		static void setTexParameterWrapT2D(TextureWrapMode paramValue);
		/**
		*	边界颜色
		*/
		static void setTexParameterBorderColor2D(const sys::Color4F& color);
		/**
		*	等级
		*/
		static void setTexParameterPriority2D(float priority);
	public:
		static void setTexGenMode(TextureCoordName name, TextureGenParameter paramType);

		static void setTexGenObjectPlane(TextureCoordName name, const float* value);

		static void setTexGenEyePlane(TextureCoordName name, const float* value);
	public:
		/**
		*	设置1d图片
		*/
		static void setTexImage1D(int nLevel, TextureParameter internalFormat, int width, int border, PixelFormat pixelFormat, PixelType pixelType, const void* data);
		/**
		*	设置2d图片
		*/
		static void setTexImage2D(int nLevel, TextureParameter internalFormat, int width, int heigth, int border, PixelFormat pixelFormat, PixelType pixelType, const void* data);
	public:
		static void setTexEnvModel(TextureEnvMode value);
		static void setTexEnvColor(const sys::Color4F& value);
	public:
		static bool isTexture(uint32_t textureID);
		// 设置纹理等级
		static void setPrioritizeTextures(int size, const uint32_t* textureIDs, const float* priorities);
	public:
		/**
		*	设置1d副图片
		*/
		static void setTexSubImage1D(int nLevel, int xOffset, int width, PixelFormat pixelFormat, PixelType pixelType, const void* data);
		/**
		*	设置2d副图片
		*/
		static void setTexSubImage2D(int nLevel, int xOffset, int yOffset, int width, int height, PixelFormat pixelFormat, PixelType pixelType, const void* data);
	public: // 纹理驻留
		static bool isTexturesResident(int n, const uint32_t* textures, bool* residences);
		static bool isTextureResident(uint32_t texture);
	public: // 激活纹理
		static void activeClientTexture(ActiveTextureName texture);
	public:
		static void activeTexture(ActiveTextureName texture);

		static void setPixelTransfer(PixelTransfer name, float value);

		static void setPixelMap(PixelMap name, int size, const float* value);
	};
}