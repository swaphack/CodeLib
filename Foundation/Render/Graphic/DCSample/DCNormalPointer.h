#pragma once

#include "macros.h"

namespace render
{
	/**
	*	绘制法线数组命令
	*/
	class DCNormalPointer : public DrawCommand
	{
	public:
		float* Pointer;
		int Count;
	public:
		DCNormalPointer();
		virtual ~DCNormalPointer();
	public:
		virtual void draw();
	};
}