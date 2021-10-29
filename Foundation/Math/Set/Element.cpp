#include "Element.h"
#include "Set.h"

math::Element::Element()
{
}

math::Element::~Element()
{
}

/**
*	����
*/

bool math::Element::isBelongTo(const Set& set) const
{
	return set.contains(*this);
}

/**
*	������
*/

bool math::Element::isNotBelongTo(const Set& set) const
{
	return !set.contains(*this);
}
