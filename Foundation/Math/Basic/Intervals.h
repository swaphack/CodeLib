#pragma once

#include "Threshold.h"
#include "Interval.h"

#include <limits>

namespace math
{
	/**
	*	char����
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
	*	uchar����
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
	*	int����
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
	*	uint����
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
	*	float����
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