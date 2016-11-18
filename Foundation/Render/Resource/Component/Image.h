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
		uint getWidth() const;
		// ��ȡͼƬ�߶�
		uint getHeight() const;
		// ��ȡͼƬ��ʽ
		int getFormat() const;
		// ��ȡͼƬ�ڲ��洢��ʽ
		int getInternalFormat() const;
		// ��ȡͼƬ��������
		uchar * getPixels() const;
	protected:
		// ����ͼƬ���
		void setWidth(uint val);
		// ����ͼƬ�߶�
		void setHeight(uint val);
		// ����ͼƬ��ʽ
		void setFormat(int val);
		// ����ͼƬ�ڲ��洢��ʽ
		void setInternalFormat(int val);
		// ����ͼƬ��������
		void setPixels(uchar * val);
	protected:
		// ͼƬ���
		uint _width;
		// ͼƬ�߶�
		uint _height;
		// ͼƬ��ʽ
		int _format;
		// ͼƬ�ڲ��洢��ʽ
		int _internalFormat;
		// ͼƬ��������
		uchar *_pixels;
	};
}