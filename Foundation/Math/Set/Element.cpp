#include "Element.h"
#include "Set.h"

using namespace math;

uint64_t Element::_sID = 0;

Element::Element()
{
	this->setID(++_sID);
}

Element::~Element()
{

}

bool Element::isBelongTo(const Set& set)
{
	return set.contains(*this);
}

bool Element::isNotBelongTo(const Set& set)
{
	return !set.contains(*this);
}

bool Element::operator==(const Element& value) const
{
	return getID() == value.getID();
}

bool Element::operator!=(const Element& value) const
{
	return getID() != value.getID();
}

bool Element::operator>=(const Element& value) const
{
	return getID() >= value.getID();
}

bool Element::operator>(const Element& value) const
{
	return getID() > value.getID();
}

bool Element::operator<(const Element& value) const
{
	return getID() < value.getID();
}

bool Element::operator<=(const Element& value) const
{
	return getID() <= value.getID();
}
