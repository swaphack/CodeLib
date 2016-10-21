#pragma once

#include "macros.h"

namespace render
{
	class DCColor : public DrawCommand
	{
	public:
		sys::Color4B Color;
	public:
		DCColor();
		virtual ~DCColor();
	public:
		virtual void draw(); 
	};
}