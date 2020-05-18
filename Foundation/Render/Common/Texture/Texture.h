#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	// �������
	class Texture : public sys::Object
	{
	public:
		Texture();
		virtual ~Texture();
	public:
		/**
		*	������
		*/
		uint32_t getTextureID() const;
		/**
		*	���
		*/
		int getWidth() const;
		/**
		*	���
		*/
		void setWidth(uint32_t val);
		/**
		*	�߶�
		*/
		uint32_t getHeight() const;
		/**
		*	�߶�
		*/
		void setHeight(uint32_t val);
		/**
		*	���
		*/
		uint32_t getDepth() const;
		/**
		*	���
		*/
		void setDepth(uint32_t val);
		/**
		*	�����Ƿ����
		*/
		bool isEnable();
	public:
		/**
		*	����ͼƬ���ݸ�ʽ����ȡ�����ʽ
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TexImageDataFormat& format, TexImageInternalFormat& internalFormat);
	protected:
		/**
		*	��������
		*/
		void initTexture();
		/**
		*	�ͷ�����
		*/
		void releaseTexture();
	protected:
		/**
		*	������
		*/
		uint32_t _textureID;
		/**
		*	���
		*/
		uint32_t _width;
		/**
		*	�߶�
		*/
		uint32_t _height;
		/**
		*	���
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

	// 2d����
	class Texture2D : public Texture
	{
	public:
		virtual void load(const sys::ImageDetail* image, const TextureSetting2D& setting = TextureSetting2D());
	};
}