#pragma once

#include <cstdint>

#include "Graphic/GLAPI/macros.h"

namespace render
{
	// ͼ�����
	class ImageDetail
	{
	public:
		ImageDetail();
		virtual ~ImageDetail();
	public:
		// ��ȡͼƬ���
		uint32_t getWidth() const;
		// ��ȡͼƬ�߶�
		uint32_t getHeight() const;
		// ��ȡͼƬ��ʽ
		PixelFormat getFormat() const;
		// ��ȡͼƬ�ڲ��洢��ʽ
		TextureParameter getInternalFormat() const;
		// ��ȡͼƬ��������
		uint8_t * getPixels() const;
	protected:
		// ����ͼƬ���
		void setWidth(uint32_t val);
		// ����ͼƬ�߶�
		void setHeight(uint32_t val);
		// ����ͼƬ��ʽ һ���������е�rgba����
		void setFormat(PixelFormat val);
		// ����ͼƬ�ڲ��洢��ʽ һ���������õ�λ��
		void setInternalFormat(TextureParameter val);
		// ����ͼƬ��������
		void setPixels(uint8_t * val);
	protected:
		// ͼƬ���
		uint32_t _width;
		// ͼƬ�߶�
		uint32_t _height;
		// ͼƬ��ʽ
		PixelFormat _format;
		// ͼƬ�ڲ��洢��ʽ
		TextureParameter _internalFormat;
		// ͼƬ��������
		uint8_t *_pixels;
	};
}