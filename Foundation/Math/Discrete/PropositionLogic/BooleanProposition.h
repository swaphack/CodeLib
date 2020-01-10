#pragma once

#include "CompoundProposition.h"

namespace math
{
	/**
	*	析取 a 或者 b
	*/
	class DisjunctiveProposition : public CompoundProposition
	{
	public:
		DisjunctiveProposition();
		DisjunctiveProposition(Proposition* a, Proposition* b);
		DisjunctiveProposition(const DisjunctiveProposition& value);
		virtual ~DisjunctiveProposition();
	public:
		/**
		*	命题A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
		/**
		*	命题B
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, B, _children, 1);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
	public:
		/**
		*	赋值
		*/
		DisjunctiveProposition& operator=(const DisjunctiveProposition& value);
	};

	/**
	*	合取 a 且 b
	*/
	class CombinedProposition : public CompoundProposition
	{
	public:
		CombinedProposition();
		CombinedProposition(Proposition* a, Proposition* b);
		CombinedProposition(const CombinedProposition& value);
		virtual ~CombinedProposition();
	public:
		/**
		*	命题A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
		/**
		*	命题B
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, B, _children, 1);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
	public:
		/**
		*	赋值
		*/
		CombinedProposition& operator=(const CombinedProposition& value);
	};

	/**
	*	否定 非a
	*	如果 a，则 非a
	*/
	class NegativeProposition : public CompoundProposition
	{
	public:
		NegativeProposition();
		NegativeProposition(Proposition* a);
		NegativeProposition(const NegativeProposition& value);
		virtual ~NegativeProposition();
	public:
		/**
		*	命题A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
	public:
		/**
		*	赋值
		*/
		NegativeProposition& operator=(const NegativeProposition& value);
	};

	/**
	*	异或 a与b 只有一个为真时，为真
	*/
	class ExclusiveORProposition : public CompoundProposition
	{
	public:
		ExclusiveORProposition();
		ExclusiveORProposition(Proposition* a, Proposition* b);
		ExclusiveORProposition(const ExclusiveORProposition& value);
		virtual ~ExclusiveORProposition();
	public:
		/**
		*	命题A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
		/**
		*	命题B
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, B, _children, 1);
	public:
		/**
		*	是否为真
		*/
		virtual bool isTrue();
	public:
		/**
		*	赋值
		*/
		ExclusiveORProposition& operator=(const ExclusiveORProposition& value);
	};
}