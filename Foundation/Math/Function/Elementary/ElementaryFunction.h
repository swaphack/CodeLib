#pragma once

#include "../Function.h"
#include "Number/Decimal.h"
#include "Basic/base.h"

namespace math
{
	//////////////////////////////////////////////////////////////////////////
	/**
	*	���Ⱥ���
	*/
	class ElementaryFunction : public Function
	{
	public:
		virtual Decimal getValue(const Decimal& var);
	};
}