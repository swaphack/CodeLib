#pragma once

#include <cstdint>

#include "macros.h"

namespace render
{
	/**
	*	����
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
		*	������С
		*/
		static void setTexParameterMinFilter2D(TextureMinFilter paramValue);
		/**
		*	����Ŵ�
		*/
		static void setTexParameterMagFilter2D(TextureMagFilter paramValue);
		/**
		*	���Ʒ�ʽ
		*/
		static void setTexParameterWrapS2D(TextureWrapMode paramValue);
		/**
		*	���Ʒ�ʽ
		*/
		static void setTexParameterWrapT2D(TextureWrapMode paramValue);
		/**
		*	�߽���ɫ
		*/
		static void setTexParameterBorderColor2D(const sys::Color4F& color);
		/**
		*	�ȼ�
		*/
		static void setTexParameterPriority2D(float priority);
	public:
		static void setTexGenMode(TextureCoordName name, TextureGenParameter paramType);

		static void setTexGenObjectPlane(TextureCoordName name, const float* value);

		static void setTexGenEyePlane(TextureCoordName name, const float* value);
	public:
		/**
		*	����1dͼƬ
		*/
		static void setTexImage1D(int nLevel, TextureParameter internalFormat, int width, int border, PixelFormat pixelFormat, PixelType pixelType, const void* data);
		/**
		*	����2dͼƬ
		*/
		static void setTexImage2D(int nLevel, TextureParameter internalFormat, int width, int heigth, int border, PixelFormat pixelFormat, PixelType pixelType, const void* data);
	public:
		static void setTexEnvModel(TextureEnvMode value);
		static void setTexEnvColor(const sys::Color4F& value);
	public:
		static bool isTexture(uint32_t textureID);
		// ��������ȼ�
		static void setPrioritizeTextures(int size, const uint32_t* textureIDs, const float* priorities);
	public:
		/**
		*	����1d��ͼƬ
		*/
		static void setTexSubImage1D(int nLevel, int xOffset, int width, PixelFormat pixelFormat, PixelType pixelType, const void* data);
		/**
		*	����2d��ͼƬ
		*/
		static void setTexSubImage2D(int nLevel, int xOffset, int yOffset, int width, int height, PixelFormat pixelFormat, PixelType pixelType, const void* data);
	public: // ����פ��
		static bool isTexturesResident(int n, const uint32_t* textures, bool* residences);
		static bool isTextureResident(uint32_t texture);
	public: // ��������
		static void activeClientTexture(ActiveTextureName texture);
	public:
		static void activeTexture(ActiveTextureName texture);

		static void setPixelTransfer(PixelTransfer name, float value);

		static void setPixelMap(PixelMap name, int size, const float* value);
	};
}