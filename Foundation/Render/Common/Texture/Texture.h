#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	// �Ƿ�ʹ�����µ�������
#define USE_NEW_TEXTURE_FUNCTION true
	// ʹ�ô洢
#define USE_TEXTURE_STORAGE true

	class Sampler;

	class TextureSetting
	{
	public:
		// ����Ԫ ActiveTextureName::TEXTURE0 + unit
		TextureMinFilter minFilter = TextureMinFilter::NEAREST;
		TextureMagFilter magFilter = TextureMagFilter::NEAREST;
		TextureWrapMode wrapS = TextureWrapMode::CLAMP;
		TextureWrapMode wrapT = TextureWrapMode::CLAMP;
		TextureWrapMode wrapR = TextureWrapMode::CLAMP;
	};

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
		*	���ò���
		*/
		void setTexParameter(TextureParameter name, int value);
		/**
		*	���ò���
		*/
		void setTexParameter(TextureParameter name, float value);
		/**
		*	���ò���
		*/
		void setTexParameter(TextureParameter name, const int* value);
		/**
		*	���ò���
		*/
		void setTexParameter(TextureParameter name, const float* value);
	public:
		/**
		*	���ò���
		*/
		void setTextureParameter(TextureParameter name, int value);
		/**
		*	���ò���
		*/
		void setTextureParameter(TextureParameter name, float value);
		/**
		*	���ò���
		*/
		void setTextureParameter(TextureParameter name, const int* value);
		/**
		*	���ò���
		*/
		void setTextureParameter(TextureParameter name, const uint32_t* value);
		/**
		*	���ò���
		*/
		void setTextureParameter(TextureParameter name, const float* value);
	public:
		/**
		*	�����Ƿ����
		*/
		bool isValid() const;
		/**
		*	������
		*/
		void bindTexture();
		/**
		*	������
		*/
		void unbindTexture();
		/**
		*	����
		*/
		void activeTexture(ActiveTextureName unit);
		/**
		*	����
		*/
		void activeTexture(uint32_t unit);
		/**
		*	������Ԫ
		*	�ȼ�
		*	activeTexture(ActiveTextureName::TEXTURE0 + unit);
		*	bindTexture();
		*/
		void bindTextureUnit(uint32_t unit);
	public:
		/**
		*	��Ч
		*/
		void enableTextureWithSampler(uint32_t unit);
		/**
		*	ʧЧ
		*/
		void enableTexture(uint32_t unit);
	public:
		/**
		*	������������
		*/
		void setTextureSetting(const TextureSetting& setting);
		/**
		*	��������
		*/
		const TextureSetting& getTextureSetting() const;
		/**
		*	Ӧ������
		*/
		void applyTextureSettingWithSampler();
		/**
		*	Ӧ������
		*/
		void applyTextureSetting();
		/**
		*	Ӧ������
		*/
		void bindSampler(uint32_t unit);
	public:
		/**
		*	��ȡ��������
		*/
		void getTextureImage(int level, TextureExternalFormat format, TextureExternalDataType type, int size, void* pixels);
	public:
		/**
		*	����mipmap
		*/
		void generateTextureMipMap();
		/**
		*	����ͼƬ���ݸ�ʽ����ȡ�����ʽ
		*/
		static void getTextureFormat(sys::ImageDataFormat imgFormat, TextureExternalFormat& format, TextureInternalSizedFormat& internalFormat, int& size);
	public:
		bool getImageDetail(sys::ImageDetail& detail, TextureExternalFormat format);
	public:
		/**
		*	��ȡͼƬ��ʽ
		*/
		static bool getImageFormat(TextureExternalFormat format, int& nUnitSize, sys::ImageDataFormat& dataFormat);
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
		/**
		*	������
		*/
		Sampler* _sampler = nullptr;

		/**
		*	��������
		*/
		TextureSetting _textureSettings;
	};
}