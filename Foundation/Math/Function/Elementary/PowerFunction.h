#pragma once

#include "ElementaryFunction.h"

namespace math
{
	/**
	*	�ݺ���
	*	y = x ^ p
	*/
	class PowerFunction : public ElementaryFunction
	{
	public:
		PowerFunction();
		PowerFunction(float power);
	public:
		/**
		*	��
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(Decimal, Power, 0.0f);
		/**
		*	ֵ������tʱ��������ֵ
		*/
		virtual Decimal getValue(const Decimal& var);
	};
}