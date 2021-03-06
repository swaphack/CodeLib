#include "Boundary.h"

using namespace math;


Boundary::Boundary()
{

}

Boundary::~Boundary()
{

}

bool Boundary::math(const Decimal& value)
{
	return false; 
}

//////////////////////////////////////////////////////////////////////////
bool LessThan::math(const Decimal& value)
{
	return getValue() < value;
}

//////////////////////////////////////////////////////////////////////////
bool LessOrEqual::math(const Decimal& value)
{
	return getValue() <= value;
}

//////////////////////////////////////////////////////////////////////////
bool MoreThan::math(const Decimal& value)
{
	return getValue() > value;
}

//////////////////////////////////////////////////////////////////////////
bool MoreOrEqual::math(const Decimal& value)
{
	return getValue() >= value;
}

//////////////////////////////////////////////////////////////////////////
bool Equal::math(const Decimal& value)
{
	return getValue() == value;
}

//////////////////////////////////////////////////////////////////////////
bool NotEqual::math(const Decimal& value)
{
	return getValue() != value;
}
