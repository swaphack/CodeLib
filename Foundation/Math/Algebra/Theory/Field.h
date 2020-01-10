#pragma once

#include "Ring.h"

namespace math
{
	/**
	*	域(Field)
	*	在交换环的基础上，还增加了二元运算除法，要求元素(除零以外)可以作除法运算，即每个非零的元素都要有乘法逆元。
	*	由此可见，域是一种可以进行加减乘除(除0以外)的代数结构，是数域与四则运算的推广。
	*	整数集合，不存在乘法逆元(1/3不是整数)，所以整数集合不是域。
	*	有理数、实数、复数可以形成域，分别叫有理数域、实数域、复数域。
	*/
	class Field : public CommutativeRing
	{
	public:
		Field doOperatorDiv(const Field& a, const Field& b)
		{
			return Field();
		}
	};
}