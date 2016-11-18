#pragma once

#include "macros.h"

namespace render
{
	// ÏñËØ
	class CtrlPixels : public Node
	{
	public:
		CtrlPixels();
		virtual ~CtrlPixels();
	public:
		static CtrlPixels* getInstance();

		virtual void draw();
		// ÉèÖÃÏñËØĞÅÏ¢
		void setPixels(int x, int y, int width, int height, uchar* data);
	private:
		uchar* _pixelsData;
		int _width;
		int _height;
	};
}