#pragma once

#include "macros.h"

namespace render
{
	/**
	*	�ռ�ת������
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