#pragma once

#include "system.h"

namespace render
{
	// ͼ�����
	class Image
	{
	public:
		Image();
		virtual ~Image();
	public:
		// ��ȡͼƬ���
		uint32 getWidth() const;
		// ��ȡͼƬ�߶�
		uint32 getHeight() const;
		// ��ȡͼƬ��ʽ
		int getFormat() const;
		// ��ȡͼƬ�ڲ��洢��ʽ
		int getInternalFormat() const;
		// ��ȡͼƬ��������
		uint8 * getPixels() const;
	protected:
		// ����ͼƬ���
		void setWidth(uint32 val);
		// ����ͼƬ�߶�
		void setHeight(uint32 val);
		// ����ͼƬ��ʽ
		void setFormat(int val);
		// ����ͼƬ�ڲ��洢��ʽ
		void setInternalFormat(int val);
		// ����ͼƬ��������
		void setPixels(uint8 * val);
	protected:
		// ͼƬ���
		uint32 _width;
		// ͼƬ�߶�
		uint32 _height;
		// ͼƬ��ʽ
		int _format;
		// ͼƬ�ڲ��洢��ʽ
		int _internalFormat;
		// ͼƬ��������
		uint8 *_pixels;
	};
}