#pragma once

#include "macros.h"

namespace render
{
	/**
	*	���Ʒ�������
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