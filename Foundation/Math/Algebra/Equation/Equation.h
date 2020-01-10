#pragma once

#include "Function/Function.h"
#include "Basic/base.h"

namespace math
{
	/**
	*	方程
	*	函数的值为0，求方程的解
	*/
	class Equation
	{
	public:
		Equation();
		virtual ~Equation();
	public:
		/**
		*	函数
		*/
		CREATE_CLASS_MEMBER(Function, Function);
	};
}