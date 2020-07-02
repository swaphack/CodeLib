#pragma once

#include <cstdint>

#include "Framework/Object.h"
#include "Memory/MemoryData.h"

namespace sys
{
	enum class ImageDataFormat
	{
		RED = 1,
		RG,
		RGB,
		RGBA,
		BGR,
		BGRA,
	};
	// ͼ�����
	class ImageDetail : public Object
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
		ImageDataFormat getDataFormat() const;
		// ��ȡͼƬ��������
		uint8_t * getPixels() const;
		// ��ȡ���ص�λ��С
		uint8_t getUnitSize();
		// ˮƽ��ת
		void flipX();
		// ��ֱ��ת
		void flipY();
	public:
		// ����ͼƬ��ʽ һ���������е�rgba����
		void setDataFormat(ImageDataFormat val);
		// ����ͼƬ��������
		void setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize);
	protected:
		// ͼƬ���
		uint32_t _width;
		// ͼƬ�߶�
		uint32_t _height;
		// ͼƬ��ʽ
		ImageDataFormat _format;
		// ͼƬ��������
		MemoryData _data;
	};
}