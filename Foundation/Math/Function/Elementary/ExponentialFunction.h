#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	ָ������
	*	y = e ^ x;
	*/
	class ExponentialFunction : public ElementaryFunction
	{
	public:
		ExponentialFunction();
		ExponentialFunction(float exp);
	public:
		/**
		*	ָ��
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Exp, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}