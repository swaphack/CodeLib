#pragma once

#include <string>
#include <set>
#include <map>

#include "mathlib.h"
#include "system.h"

namespace tool
{
	// 纹理打包
	class AtlasPacker
	{
	public:
		AtlasPacker();
		virtual ~AtlasPacker();
	public:
		/**
		*	设置大小
		*/
		void setSize(int width, int height);
		/**
		*	获取宽度
		*/
		int getWidth() const;
		/**
		*	获取高度
		*/
		int getHeight() const;
		/**
		*	y轴反调
		*/
		void setReverseY(bool reverse);
		/**
		*	获取y轴反调
		*/
		bool isReverseY() const;
	public:
		/**
		*	保存成rgba 32位png图片
		*/
		void saveImage(const std::string& imgFilePath, uint8_t* data, sys::ImageDataFormat format = sys::ImageDataFormat::RGBA);
	protected:
		// 大小
		math::IntSize _size;
		// y轴是否相反
		bool _reverseY = false;
	};
}