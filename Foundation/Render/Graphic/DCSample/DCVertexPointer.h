#pragma once

#include "macros.h"

namespace render
{
	/**
	*	���ƶ�������
	*/
	class DCVertexPointer : public DrawCommand
	{
	public:
		float* Pointer;
		int Count;
	public:
		DCVertexPointer();
		virtual ~DCVertexPointer();
	public:
		virtual void draw();
	};
}