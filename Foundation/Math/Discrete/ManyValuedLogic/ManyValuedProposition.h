#pragma once

#include "../PropositionLogic/PrimaryProposition.h"

namespace math
{
	/**
	*	多值命题
	*/
	class ManyValuedProposition : public PrimaryProposition
	{
	public:
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Percent, 0);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue() const;
		/**
		*	获取结果的值
		*/
		virtual float getValue() const;
		/**
		*	是否相同
		*/
		virtual bool hasSameLogic(Proposition* proposition);
	};
}