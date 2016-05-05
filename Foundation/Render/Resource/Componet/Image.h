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
		uint getWidth() const;
		// 获取图片高度
		uint getHeight() const;
		// 获取图片格式
		int getFormat() const;
		// 获取图片内部存储格式
		int getInternalFormat() const;
		// 获取图片像素数据
		uchar * getPixels() const;
	protected:
		// 设置图片宽度
		void setWidth(uint val);
		// 设置图片高度
		void setHeight(uint val);
		// 设置图片格式
		void setFormat(int val);
		// 设置图片内部存储格式
		void setInternalFormat(int val);
		// 设置图片像素数据
		void setPixels(uchar * val);
	protected:
		// 图片宽度
		uint _width;
		// 图片高度
		uint _height;
		// 图片格式
		int _format;
		// 图片内部存储格式
		int _internalFormat;
		// 图片像素数据
		uchar *_pixels;
	};
}