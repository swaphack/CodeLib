#pragma once

#include <cstdint>

#include "Graphic/GLAPI/macros.h"

namespace render
{
	// ͼ�����
	class ImageDetail : public sys::Object
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
		TexImageDataFormat getFormat() const;
		// ��ȡͼƬ�ڲ��洢��ʽ
		TexImageInternalFormat getInternalFormat() const;
		// ��ȡͼƬ��������
		uint8_t * getPixels() const;
	protected:
		// ����ͼƬ��ʽ һ���������е�rgba����
		void setFormat(TexImageDataFormat val);
		// ����ͼƬ�ڲ��洢��ʽ һ���������õ�λ��
		void setInternalFormat(TexImageInternalFormat val);
		// ����ͼƬ��������
		void setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize);
	protected:
		// ͼƬ���
		uint32_t _width;
		// ͼƬ�߶�
		uint32_t _height;
		// ͼƬ��ʽ
		TexImageDataFormat _format;
		// ͼƬ�ڲ��洢��ʽ
		TexImageInternalFormat _internalFormat;
		// ͼƬ��������
		uint8_t *_pixels;
	};
}