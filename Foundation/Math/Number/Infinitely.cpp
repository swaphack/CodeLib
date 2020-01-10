#include "Infinitely.h"

using namespace math;


InfinitelyGreat InfinitelySmall::inverse()
{
	return InfinitelyGreat();
}

InfinitelySmall InfinitelySmall::operator+(const InfinitelySmall& value)
{
	return InfinitelySmall();
}

InfinitelySmall InfinitelySmall::operator+(const Number& value)
{
	return InfinitelySmall();
}

InfinitelySmall InfinitelySmall::operator*(const InfinitelySmall& value)
{
	return InfinitelySmall();
}

//////////////////////////////////////////////////////////////////////////
InfinitelySmall InfinitelyGreat::inverse()
{
	return InfinitelySmall();
}
