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
	};

	/**
	*	双重蕴含式 如果a,那么b ，且 若b,那么a
	*/
	class DoubleImplicateProposition : public CompoundProposition
	{
	public:
		DoubleImplicateProposition();
		DoubleImplicateProposition(Proposition* a, Proposition* b);
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
	};
}