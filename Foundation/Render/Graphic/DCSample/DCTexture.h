#pragma once

#include "macros.h"

namespace render
{
	/**
	*	����ͼ������
	*/
	class DCTexture : public DrawCommand
	{
	public:
		sys::Vector* Position;
		sys::Color4B* Color;
		sys::Vector* Coord;
	public:
		DCTexture();
		virtual ~DCTexture();
	public:
		virtual void draw();
	};
}