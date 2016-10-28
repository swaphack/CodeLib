#pragma once

#include "macros.h"

namespace render
{
	/**
	*	»æÖÆ·¨ÏßÃüÁî
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