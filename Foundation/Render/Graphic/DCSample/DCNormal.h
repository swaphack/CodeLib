#pragma once

#include "macros.h"

namespace render
{
	/**
	*	»æÖÆ·¨ÏßÃüÁî
	*/
	class DCNormal : public DrawCommand
	{
	public:
		sys::Vector* Normal;
	public:
		DCNormal();
		virtual ~DCNormal();
	public:
		virtual void draw();
	};
}