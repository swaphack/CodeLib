#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	��������
	*	y = log (x);
	*/
	class LogarithmicFunction : public ElementaryFunction
	{
	public:
		LogarithmicFunction();
		LogarithmicFunction(float base);
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Base, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}