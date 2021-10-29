#pragma once

#include "Number.h"

namespace math
{
	/**
	*	无穷数
	*/
	class Infinitely : public Number
	{

	};

	class InfinitelyGreat;

	/**
	*	无穷小
	*/
	class InfinitelySmall : public Infinitely
	{
	public:
		/**
		*	倒数
		*/
		InfinitelyGreat inverse();
	public:
		InfinitelySmall operator+(const InfinitelySmall& value) const;
		InfinitelySmall operator*(const InfinitelySmall& value) const;
		InfinitelySmall operator+(const Number& value) const;
	};

	/**
	*	无穷大
	*/
	class InfinitelyGreat : public Infinitely
	{
	public:
		/**
		*	倒数
		*/
		InfinitelySmall inverse() const;
	};
}