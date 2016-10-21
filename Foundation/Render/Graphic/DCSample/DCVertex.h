#pragma once

#include "macros.h"

namespace render
{
	/**
	*	ªÊ÷∆∂•µ„√¸¡Ó
	*/
	class DCVertex : public DrawCommand
	{
	public:
		sys::Vector Vertex;
	public:
		DCVertex();
		virtual ~DCVertex();
	public:
		virtual void draw() = 0;
	};
}