#pragma once

#include "macros.h"

namespace render
{
	/**
	*	�������
	*/
	class DCBlend : public DrawCommand
	{
	public:
		int Src;
		int Dest;
	public:
		DCBlend();
		virtual ~DCBlend();
	public:
		virtual void draw();
	};
}