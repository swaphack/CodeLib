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
	};
}