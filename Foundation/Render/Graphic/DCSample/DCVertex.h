#pragma once

#include "macros.h"

namespace render
{
	/**
	*	���ƶ�������
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