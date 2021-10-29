#pragma once

#include <cstdint>

#include "Framework/Object.h"
#include "Memory/MemoryData.h"

namespace sys
{
	enum class ImageDataFormat
	{
		NONE,
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
		uint8_t getUnitSize() const;
		// ��ȡָ��
		uint8_t* getPtr(uint32_t offset) const;
		// ��ȡָ��
		uint8_t getValue(uint32_t offset) const;
		// ˮƽ��ת
		void flipX();
		// ��ֱ��ת
		void flipY();
		// ��ת90��
		void rotate90();
		// ��ת-90��
		void rotate270();
		// ��չ��ʽ��RED,RG,RGB=>RGBA BGR=>BGRA
		void expandFormat();
	public:
		// ����ͼƬ��ʽ һ���������е�rgba����
		void setDataFormat(ImageDataFormat val);
		// ����ͼƬ��������
		void setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize);
		// ����ͼƬ��������
		void setPixels(const MemoryData& data, uint32_t width, uint32_t height, int nUnitSize);
	public:
		// ��ȡ���ص�λ��С
		static uint8_t getUnitSize(ImageDataFormat val);
	protected:
		// ͼƬ���
		uint32_t _width = 0;
		// ͼƬ�߶�
		uint32_t _height = 0;
		// ͼƬ��ʽ
		ImageDataFormat _format = ImageDataFormat::RGB;
		// ͼƬ��������
		MemoryData _data;
	};
}