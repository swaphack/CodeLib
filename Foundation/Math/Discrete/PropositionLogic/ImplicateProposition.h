#pragma once

#include "CompoundProposition.h"

namespace math
{
	/**
	*	�̺�ʽ ���a,��ôb
	*/
	class ImplicateProposition : public CompoundProposition
	{
	public:
		ImplicateProposition();
		ImplicateProposition(Proposition* a, Proposition* b);
		ImplicateProposition(const ImplicateProposition& value);
		virtual ~ImplicateProposition();
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
		/**
		*	��¡�ڵ㣬�������ӽڵ�
		*/
		virtual Proposition* clone();
		/**
		*	��¡�ڵ㣬�����ӽڵ�
		*/
		virtual Proposition* deepClone();
	public:
		/**
		*	��ֵ
		*/
		ImplicateProposition& operator=(const ImplicateProposition& value);
	};

	/**
	*	˫���̺�ʽ ���a,��ôb ���� ��b,��ôa
	*/
	class DoubleImplicateProposition : public CompoundProposition
	{
	public:
		DoubleImplicateProposition();
		DoubleImplicateProposition(Proposition* a, Proposition* b);
		DoubleImplicateProposition(const DoubleImplicateProposition& value);
		virtual ~DoubleImplicateProposition();
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
		/**
		*	��¡�ڵ㣬�������ӽڵ�
		*/
		virtual Proposition* clone();
		/**
		*	��¡�ڵ㣬�����ӽڵ�
		*/
		virtual Proposition* deepClone();
	public:
		/**
		*	��ֵ
		*/
		DoubleImplicateProposition& operator=(const DoubleImplicateProposition& value);
	};
}