#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	指数函数
	*	y = e ^ x;
	*/
	class ExponentialFunction : public ElementaryFunction
	{
	public:
		ExponentialFunction();
		ExponentialFunction(float exp);
	public:
		/**
		*	指数
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Exp, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}