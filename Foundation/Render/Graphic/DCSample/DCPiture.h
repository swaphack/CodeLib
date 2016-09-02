#pragma once

#include "macros.h"

namespace render
{
	class DCColor : public DrawCommand
	{
	public:
		uchar* Pointer;
		int Count;
	public:
		DCColor();
		virtual ~DCColor();
	public:
		virtual void draw();
	};
}