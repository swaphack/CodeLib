#pragma once

#include "macros.h"

namespace render
{
	// ����ͼƬ
	class DCPicture : public DrawCommand
	{
	public:
		uchar* Pointer;
		int Count;
	public:
		DCPicture();
		virtual ~DCPicture();
	public:
		virtual void draw();
	};
}