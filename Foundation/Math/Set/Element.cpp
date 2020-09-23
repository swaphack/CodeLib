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

bool math::Element::isBelongTo(const Set& set)
{
	return set.contains(*this);
}

/**
*	������
*/

bool math::Element::isNotBelongTo(const Set& set)
{
	return !set.contains(*this);
}
