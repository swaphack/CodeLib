#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	对数函数
	*	y = log (x);
	*/
	class LogarithmicFunction : public ElementaryFunction
	{
	public:
		LogarithmicFunction();
		LogarithmicFunction(float base);
	public:
		/**
		*	底数
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Base, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}