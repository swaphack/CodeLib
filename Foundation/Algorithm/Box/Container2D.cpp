#include "Container2D.h"

alg::Container2D::Container2D()
{
}

alg::Container2D::~Container2D()
{
}

void alg::Container2D::setSize(const math::Size& size)
{
	_containerSize = size;
}

const math::Size& alg::Container2D::getSize() const
{
	return _containerSize;
}

void alg::Container2D::addItem(const Container2D::Item& item)
{
	_items[item.boxID] = item;
}

void alg::Container2D::removeItem(const Container2D::Item& item)
{
	_items.erase(item.boxID);
}

void alg::Container2D::removeAllItems()
{
	_items.clear();
}

bool alg::Container2D::getLayoutWay(std::map<int, math::Vector2>& positions)
{


	return false;
}
