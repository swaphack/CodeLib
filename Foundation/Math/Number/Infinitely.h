#pragma once

#include "Number.h"

namespace math
{
	/**
	*	������
	*/
	class Infinitely : public Number
	{

	};

	class InfinitelyGreat;

	/**
	*	����С
	*/
	class InfinitelySmall : public Infinitely
	{
	public:
		/**
		*	����
		*/
		InfinitelyGreat inverse();
	public:
		InfinitelySmall operator+(const InfinitelySmall& value) const;
		InfinitelySmall operator*(const InfinitelySmall& value) const;
		InfinitelySmall operator+(const Number& value) const;
	};

	/**
	*	�����
	*/
	class InfinitelyGreat : public Infinitely
	{
	public:
		/**
		*	����
		*/
		InfinitelySmall inverse() const;
	};
}