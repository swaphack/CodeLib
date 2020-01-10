#pragma once

#include "CompoundProposition.h"

namespace math
{
	/**
	*	��ȡ a ���� b
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
		*	����A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
		/**
		*	����B
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, B, _children, 1);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
	public:
		/**
		*	��ֵ
		*/
		DisjunctiveProposition& operator=(const DisjunctiveProposition& value);
	};

	/**
	*	��ȡ a �� b
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
		*	����A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
		/**
		*	����B
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, B, _children, 1);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
	public:
		/**
		*	��ֵ
		*/
		CombinedProposition& operator=(const CombinedProposition& value);
	};

	/**
	*	�� ��a
	*	��� a���� ��a
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
		*	����A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
	public:
		/**
		*	��ֵ
		*/
		NegativeProposition& operator=(const NegativeProposition& value);
	};

	/**
	*	��� a��b ֻ��һ��Ϊ��ʱ��Ϊ��
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
		*	����A
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, A, _children, 0);
		/**
		*	����B
		*/
		CREATE_CLASS_VECTOR_MEMBER(Proposition*, B, _children, 1);
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isTrue();
	public:
		/**
		*	��ֵ
		*/
		ExclusiveORProposition& operator=(const ExclusiveORProposition& value);
	};
}