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
		Texture(TextureTarget target);
		virtual ~Texture();
	public:
		/**
		*	������
		*/
		uint32_t getTextureID() const;
		/**
		*	��������
		*/
		TextureTarget getTextureTarget();
	public:
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
	public:
		/**
		*	�����Ƿ����
		*/
		bool isValid();
		/**
		*	������
		*/
		void bindTexture();
		/**
		*	������
		*/
		void unbindTexture();
		/**
		*	������Ԫ
		*/
		void bindTextureUnit(uint32_t unit);
	public:
		/**
		*	��ȡ��������
		*/
		void getTextureImage(int level, TextureDataFormat format, TextureDataType type, int size, void* pixels);
	public:
		/**
		*	����ͼƬ���ݸ�ʽ����ȡ�����ʽ
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TextureDataFormat& format, TextureInternalFormat& internalFormat);
		/**
		*	����ͼƬ���ݸ�ʽ����ȡ�����ʽ
		*/
		static void getStorageTextureFormat(sys::ImageDataFormat imgFormat, TextureDataFormat& format, TextureInternalFormat& internalFormat);
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
		uint32_t _textureID = 0;
		/**
		*	��������
		*/
		TextureTarget _textureTarget = TextureTarget::NONE;
		/**
		*	���
		*/
		uint32_t _width = 0;
		/**
		*	�߶�
		*/
		uint32_t _height = 0;
		/**
		*	���
		*/
		uint32_t _depth = 0;
	};
}