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
		// 获取指针
		uint8_t* getPtr(uint32_t offset) const;
		// 获取指针
		uint8_t getValue(uint32_t offset) const;
		// 水平翻转
		void flipX();
		// 垂直翻转
		void flipY();
		// 旋转90度
		void rotate90();
		// 旋转-90度
		void rotate270();
		// 扩展格式，RED,RG,RGB=>RGBA BGR=>BGRA
		void expandFormat();
	public:
		// 设置图片格式 一个像素所有的rgba类型
		void setDataFormat(ImageDataFormat val);
		// 设置图片像素数据
		void setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize);
		// 设置图片像素数据
		void setPixels(const MemoryData& data, uint32_t width, uint32_t height, int nUnitSize);
	public:
		// 获取像素单位大小
		static uint8_t getUnitSize(ImageDataFormat val);
	protected:
		// 图片宽度
		uint32_t _width = 0;
		// 图片高度
		uint32_t _height = 0;
		// 图片格式
		ImageDataFormat _format = ImageDataFormat::RGB;
		// 图片像素数据
		MemoryData _data;
	};
}