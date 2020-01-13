#pragma once

#include "Basic/Collection/NodeCache.h"
#include "Proposition.h"
#include "PrimaryProposition.h"
#include "BooleanProposition.h"

namespace math
{
	/**
	*	�ȼ۹���
	*/
	class EquivalenceRule
	{
	public:
		EquivalenceRule();
		virtual ~EquivalenceRule();
	public:
		/**
		*	��ȡ�ȼ�ʽ
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
		*	��ȡ�ȼ�ʽ
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
		*	��ȡ�ȼ�ʽ
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
		*	��ȡ�ȼ�ʽ
		*/
		virtual CompoundProposition* GetEquivalenceProposition(CompoundProposition* proposition);
	};
}