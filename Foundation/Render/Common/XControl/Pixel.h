#pragma once

#include "../Node/import.h"

namespace render
{
	// ����
	class Pixel
	{
	private:
		Pixel();
		virtual ~Pixel();
	public:
		// ��ȡָ��λ�õ�����
		static sys::Color4B getPixel(float x, float y);
		// ����ָ��λ�õ�����
		static void setPixel(float x, float y, int width, int height, const sys::Color4B& color);
	};
}