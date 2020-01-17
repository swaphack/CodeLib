#pragma once

#include "CompoundProposition.h"

namespace math
{
	/**
	*	蕴含式 如果a,那么b
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
		*	赋值
		*/
		ImplicateProposition& operator=(const ImplicateProposition& value);
	};

	/**
	*	双重蕴含式 如果a,那么b ，且 若b,那么a
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
		*	赋值
		*/
		DoubleImplicateProposition& operator=(const DoubleImplicateProposition& value);
	};
}