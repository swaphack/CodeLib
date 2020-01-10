#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	常数函数
	*/
	class ConstantFunction : public ElementaryFunction
	{
	public:
		ConstantFunction();
		ConstantFunction(float constant);
	public:
		/**
		*	常数
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Constant, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}