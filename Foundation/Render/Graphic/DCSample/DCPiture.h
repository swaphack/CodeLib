#pragma once

#include "macros.h"

namespace render
{
	// ªÊ÷∆Õº∆¨
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