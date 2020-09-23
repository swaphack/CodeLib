#include "Element.h"
#include "Set.h"

math::Element::Element()
{
}

math::Element::~Element()
{
}

/**
*	ÊôÓÚ
*/

bool math::Element::isBelongTo(const Set& set)
{
	return set.contains(*this);
}

/**
*	²»ÊôÓÚ
*/

bool math::Element::isNotBelongTo(const Set& set)
{
	return !set.contains(*this);
}
