#pragma once

#include "macros.h"

namespace render
{
	// ����
	class CtrlPixels : public Node
	{
	public:
		CtrlPixels();
		virtual ~CtrlPixels();
	public:
		static CtrlPixels* getInstance();

		virtual void draw();
		// ����������Ϣ
		void setPixels(int x, int y, int width, int height, uchar* data);
	private:
		uchar* _pixelsData;
		int _width;
		int _height;
	};
}