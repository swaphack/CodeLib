#pragma once

#include "Basic/Collection/NodeCache.h"
#include "Proposition.h"
#include "PrimaryProposition.h"
#include "BooleanProposition.h"

namespace math
{
	/**
	*	等价规则
	*/
	class EquivalenceRule
	{
	public:
		EquivalenceRule();
		virtual ~EquivalenceRule();
	public:
		/**
		*	获取等价式
		*/
		virtual CompoundProposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(a&b) = (!a) | (!b);
	*/
	class EquivalenceRule1 : public EquivalenceRule
	{
	public:
		EquivalenceRule1();
		virtual ~EquivalenceRule1();
	public:
		/**
		*	获取等价式
		*/
		virtual CompoundProposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	!(a|b) = (!a) & (!b);
	*/
	class EquivalenceRule2 : public EquivalenceRule
	{
	public:
		EquivalenceRule2();
		virtual ~EquivalenceRule2();
	public:
		/**
		*	获取等价式
		*/
		virtual CompoundProposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};

	//////////////////////////////////////////////////////////////////////////
	/**
	*	a | (b&c) = (a|b) & (a|c);
	*/
	class EquivalenceRule3 : public EquivalenceRule
	{
	public:
		EquivalenceRule3();
		virtual ~EquivalenceRule3();
	public:
		/**
		*	获取等价式
		*/
		virtual CompoundProposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
}