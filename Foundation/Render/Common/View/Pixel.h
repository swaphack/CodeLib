#pragma once

#include "system.h"

namespace render
{
	/**
	*	像素处理
	*/
	class Pixel
	{
	public:
		Pixel();
		virtual ~Pixel();
	public:
		/**
		*	获取像素缓存数据
		*/
		const sys::MemoryData& getPixelData() const;
	public:
		/**
		*	加载指定位置的像素
		*/ 
		void loadPointPixel(float x, float y);
		/**
		*	加载指定矩形的像素
		*/
		void loadRectPixel(float x, float y, float width, float height);
	public:
		/**
		*	获取指定位置的像素
		*/
		static sys::Color4B readPixelColor(float x, float y);
	private:
		// 像素缓存数据
		sys::MemoryData _blockData;
	};
}