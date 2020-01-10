#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	��������
	*/
	class ConstantFunction : public ElementaryFunction
	{
	public:
		ConstantFunction();
		ConstantFunction(float constant);
	public:
		/**
		*	����
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Constant, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}