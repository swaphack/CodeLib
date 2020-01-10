#include "Set.h"

using namespace math;


Set::Set()
{

}

Set::~Set()
{

}

bool Set::contains(const Element& value) const
{
	return false;
}

const Set* Set::None()
{
	static Set sNoneSet;
	return &sNoneSet;
}

bool Set::isNone() const
{
	return true;
}

bool Set::isSubSetEqual(const Set& value) const
{
	return true;
}

bool Set::isSubSet(const Set& value) const
{
	return false;
}

bool Set::isSupSetEqual(const Set& value) const
{
	return false;
}

bool Set::isSupSet(const Set& value) const
{
	return false;
}

Set Set::unionAll(const Set& value) const
{
	return value;
}

Set Set::intersect(const Set& value) const
{
	return *this;
}

Set Set::complementary(const Set& value) const
{
	return *this;
}

Set Set::successor() const
{
	return *this;
}
