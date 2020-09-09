#include "FiniteSet.h"

using namespace math;


FiniteSet::FiniteSet()
{

}

FiniteSet::FiniteSet(const FiniteSet& value)
{
	*this = value;
}

FiniteSet::~FiniteSet()
{

}

bool FiniteSet::contains(const Element& value) const
{
	auto it = _elements.find(value);
	return it != _elements.end();
}

void FiniteSet::addElement(const Element& value)
{
	_elements.insert(value);
}

void FiniteSet::removeElement(const Element& value)
{
	_elements.erase(value);
}

void FiniteSet::removeAllElements()
{
	_elements.clear();
}

const std::set<Element>& FiniteSet::getAllElements() const
{
	return _elements;
}

int32_t FiniteSet::getCount() const
{
	return _elements.size();
}

bool FiniteSet::isNone() const
{
	return getCount() == 0;
}

bool FiniteSet::isSubSetEqual(const FiniteSet& value) const
{
	auto values = this->getAllElements();
	for (auto& item : values)
	{
		if (!value.contains(item))
		{
			return false;
		}
	}

	return true;
}

bool FiniteSet::isSubSet(const FiniteSet& value) const
{
	if (this->isSubSetEqual(value))
	{
		return this->getCount() != value.getCount();
	}

	return false;
}

bool FiniteSet::isSupSetEqual(const FiniteSet& value) const
{
	return value.isSubSetEqual(*this);
}

bool FiniteSet::isSupSet(const FiniteSet& value) const
{
	return value.isSubSet(*this);
}

FiniteSet FiniteSet::unionAll(const FiniteSet& value) const
{
	FiniteSet set = *this;
	auto values = value.getAllElements();
	for (auto& item : values)
	{
		if (!this->contains(item))
		{
			set.addElement(item);
		}
	}
	return set;
}

FiniteSet FiniteSet::intersect(const FiniteSet& value) const
{
	FiniteSet set;
	auto values = value.getAllElements();
	for (auto& item : values)
	{
		if (this->contains(item))
		{
			set.addElement(item);
		}
	}
	return set;
}

FiniteSet FiniteSet::complementary(const FiniteSet& value) const
{
	FiniteSet set = *this;
	auto values = value.getAllElements();
	for (auto& item : values)
	{
		if (this->contains(item))
		{
			set.removeElement(item);
		}
	}
	return set;
}

FiniteSet FiniteSet::operator+(const Element& value) const
{
	FiniteSet set = *this;
	set.addElement(value);
	return set;
}

FiniteSet FiniteSet::operator-(const Element& value) const
{
	FiniteSet set = *this;
	set.removeElement(value);
	return set;
}

FiniteSet& FiniteSet::operator+=(const Element& value)
{
	this->addElement(value);
	return *this;
}

FiniteSet& FiniteSet::operator-=(const Element& value)
{
	this->removeElement(value);
	return *this;
}

FiniteSet& FiniteSet::operator=(const FiniteSet& value)
{
	this->removeAllElements();
	auto allElements = value.getAllElements();
	for (auto& item : allElements)
	{
		this->addElement(item);
	}

	return *this;
}

bool FiniteSet::operator==(const FiniteSet& value) const
{
	if (this->isSubSetEqual(value) && value.isSubSetEqual(*this))
	{
		return true;
	}

	return false;
}

bool FiniteSet::operator!=(const FiniteSet& value) const
{
	if (!this->isSubSetEqual(value) || ! value.isSubSetEqual(*this))
	{
		return true;
	}

	return false;
}

FiniteSet FiniteSet::successor() const
{
	FiniteSet outter = *this;
	FiniteSet set = *this;
	outter.addElement(set);
	return set;
}


