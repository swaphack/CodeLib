#pragma once

#include "macros.h"

namespace render
{
	/**
	*	¿Õ¼ä×ª»»ÃüÁî
	*/
	class DCSpace : public DrawCommand
	{
	public:
		sys::Vector* Point;
		sys::Vector* Scale;
	public:
		DCSpace();
		virtual ~DCSpace();
	public:

	};
}