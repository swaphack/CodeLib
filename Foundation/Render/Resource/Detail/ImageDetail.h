#pragma once

#include "system.h"

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
		int getFormat() const;
		// ��ȡͼƬ�ڲ��洢��ʽ
		int getInternalFormat() const;
		// ��ȡͼƬ��������
		uint8_t * getPixels() const;
	protected:
		// ����ͼƬ���
		void setWidth(uint32_t val);
		// ����ͼƬ�߶�
		void setHeight(uint32_t val);
		// ����ͼƬ��ʽ
		void setFormat(int val);
		// ����ͼƬ�ڲ��洢��ʽ
		void setInternalFormat(int val);
		// ����ͼƬ��������
		void setPixels(uint8_t * val);
	protected:
		// ͼƬ���
		uint32_t _width;
		// ͼƬ�߶�
		uint32_t _height;
		// ͼƬ��ʽ
		int _format;
		// ͼƬ�ڲ��洢��ʽ
		int _internalFormat;
		// ͼƬ��������
		uint8_t *_pixels;
	};
}