#pragma once

#include "../Node/import.h"

namespace render
{
	// 像素
	class Pixel
	{
	private:
		Pixel();
		virtual ~Pixel();
	public:
		// 获取指定位置的像素
		static sys::Color4B getPixel(float x, float y);
		// 设置指定位置的像素
		static void setPixel(float x, float y, int width, int height, const sys::Color4B& color);
	};
}