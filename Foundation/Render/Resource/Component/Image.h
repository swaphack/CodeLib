#pragma once

#include "system.h"

namespace render
{
	// 图像基类
	class Image
	{
	public:
		Image();
		virtual ~Image();
	public:
		// 获取图片宽度
		uint32 getWidth() const;
		// 获取图片高度
		uint32 getHeight() const;
		// 获取图片格式
		int getFormat() const;
		// 获取图片内部存储格式
		int getInternalFormat() const;
		// 获取图片像素数据
		uint8 * getPixels() const;
	protected:
		// 设置图片宽度
		void setWidth(uint32 val);
		// 设置图片高度
		void setHeight(uint32 val);
		// 设置图片格式
		void setFormat(int val);
		// 设置图片内部存储格式
		void setInternalFormat(int val);
		// 设置图片像素数据
		void setPixels(uint8 * val);
	protected:
		// 图片宽度
		uint32 _width;
		// 图片高度
		uint32 _height;
		// 图片格式
		int _format;
		// 图片内部存储格式
		int _internalFormat;
		// 图片像素数据
		uint8 *_pixels;
	};
}