#pragma once

#include "../PropositionLogic/Proposition.h"

namespace math
{
	/**
	*	多值命题
	*/
	class ManyValuedProposition : public Proposition
	{
	public:
		ManyValuedProposition();
		ManyValuedProposition(float percent);
		ManyValuedProposition(const ManyValuedProposition& proposition);
		virtual ~ManyValuedProposition();
	public:
		/**
		*	百分比
		*/
		CREATE_CLASS_MEMBER_WITH_DEFAULT(float, Percent, 0);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
		/**
		*	是否有相同的逻辑
		*/
		virtual bool hasSameLogic(Proposition* proposition);
		/**
		*	克隆节点，不包含子节点
		*/
		virtual Proposition* clone();
		/**
		*	克隆节点，包含子节点
		*/
		virtual Proposition* deepClone();
	public:
		/**
		*	复制
		*/
		ManyValuedProposition& operator=(const ManyValuedProposition& value);
	};
}