#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	幂函数
	*	y = x ^ p
	*/
	class PowerFunction : public ElementaryFunction
	{
	public:
		PowerFunction();
		PowerFunction(float power);
	public:
		/**
		*	幂
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Power, 0.0f);
		/**
		*	值趋向于t时，求函数的值
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}