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
	// 图像基类
	class ImageDetail : public Object
	{
	public:
		ImageDetail();
		virtual ~ImageDetail();
	public:
		// 获取图片宽度
		uint32_t getWidth() const;
		// 获取图片高度
		uint32_t getHeight() const;
		// 获取图片格式
		ImageDataFormat getDataFormat() const;
		// 获取图片像素数据
		uint8_t * getPixels() const;
		// 获取像素单位大小
		uint8_t getUnitSize() const;

		uint8_t* getPtr(uint32_t offset) const;
		// 水平翻转
		void flipX();
		// 垂直翻转
		void flipY();
	public:
		// 设置图片格式 一个像素所有的rgba类型
		void setDataFormat(ImageDataFormat val);
		// 设置图片像素数据
		void setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize);
	protected:
		// 图片宽度
		uint32_t _width;
		// 图片高度
		uint32_t _height;
		// 图片格式
		ImageDataFormat _format;
		// 图片像素数据
		MemoryData _data;
	};
}