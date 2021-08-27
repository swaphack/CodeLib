#pragma once

#include "Threshold.h"
#include "Interval.h"

#include <limits>

namespace math
{
	/**
	*	char区间
	*/
	struct CharInterval : public Interval<char>
	{
	public:
		CharInterval() : Interval<char>(CHAR_MIN, CHAR_MAX)
		{
		}
		CharInterval(char min, char max) : Interval<char>(min, max)
		{
		}
	};

	/**
	*	uchar区间
	*/
	struct UCharInterval : public Interval<unsigned char>
	{
	public:
		UCharInterval() : Interval<unsigned char>(0, UCHAR_MAX)
		{
		}
		UCharInterval(unsigned char min, unsigned char max) : Interval<unsigned char>(min, max)
		{
		}
	};

	/**
	*	int区间
	*/
	struct IntInterval : public Interval<int>
	{
	public:
		IntInterval(): Interval<int>(INT_MIN, INT_MAX)
		{
		}
		IntInterval(int min, int max) : Interval<int>(min, max)
		{
		}
	};

	/**
	*	uint区间
	*/
	struct UIntInterval : public Interval<unsigned int>
	{
	public:
		UIntInterval() : Interval<unsigned int>(0, UINT_MAX)
		{
		}
		UIntInterval(unsigned int min, unsigned int max) : Interval<unsigned int>(min, max)
		{
		}
	};

	/**
	*	float区间
	*/
	struct FloatInterval : public Interval<float>
	{
	public:
		FloatInterval() : Interval<float>(FLT_MIN, FLT_MAX)
		{
		}
		FloatInterval(float min, float max) : Interval<float>(min, max)
		{
		}
	};
}