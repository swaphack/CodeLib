#pragma once

#include "Function/Function.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	����
	*	������ֵΪ0���󷽳̵Ľ�
	*/
	class Equation
	{
	public:
		Equation();
		virtual ~Equation();
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER(Function, Function);
	};
}