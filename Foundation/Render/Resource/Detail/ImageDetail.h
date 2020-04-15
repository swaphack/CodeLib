#pragma once

#include <cstdint>

#include "Graphic/GLAPI/macros.h"

namespace render
{
	// 图像基类
	class ImageDetail : public sys::Object
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
		PixelFormat getFormat() const;
		// 获取图片内部存储格式
		TextureParameter getInternalFormat() const;
		// 获取图片像素数据
		uint8_t * getPixels() const;
	protected:
		// 设置图片格式 一个像素所有的rgba类型
		void setFormat(PixelFormat val);
		// 设置图片内部存储格式 一个像素所用的位数
		void setInternalFormat(TextureParameter val);
		// 设置图片像素数据
		void setPixels(uint8_t * val, uint32_t width, uint32_t height, int nUnitSize);
	protected:
		// 图片宽度
		uint32_t _width;
		// 图片高度
		uint32_t _height;
		// 图片格式
		PixelFormat _format;
		// 图片内部存储格式
		TextureParameter _internalFormat;
		// 每个像素的单位
		int _unitSize = 0;
		// 图片像素数据
		uint8_t *_pixels;
	};
}