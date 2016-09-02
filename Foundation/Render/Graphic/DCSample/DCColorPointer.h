#pragma once

#include "macros.h"

namespace render
{
	class DCColorPointer : public DrawCommand
	{
	public:
		uchar* Pointer;
		int Count;
	public:
		DCColorPointer();
		virtual ~DCColorPointer();
	public:
		virtual void draw();
	};
}