#include "Infinitely.h"

using namespace math;


InfinitelyGreat InfinitelySmall::inverse()
{
	return InfinitelyGreat();
}

InfinitelySmall InfinitelySmall::operator+(const InfinitelySmall& value) const
{
	return InfinitelySmall();
}

InfinitelySmall InfinitelySmall::operator+(const Number& value) const
{
	return InfinitelySmall();
}

InfinitelySmall InfinitelySmall::operator*(const InfinitelySmall& value) const
{
	return InfinitelySmall();
}

//////////////////////////////////////////////////////////////////////////
InfinitelySmall InfinitelyGreat::inverse() const
{
	return InfinitelySmall();
}
