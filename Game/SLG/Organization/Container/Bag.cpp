#include "Bag.h"

using namespace slg;

Bag::Bag()
{

}

Bag::~Bag()
{
	this->removeAllItems();
}

bool Bag::addItem(Item* item)
{
	if (item == nullptr)
	{
		return false;
	}

	SAFE_RETAIN(item);

	_items[item->getItemID()] = item;
}

bool Bag::removeItem(int itemID)
{
	std::map<int, Item*>::iterator iter = _items.find(itemID);
	if (iter != _items.end())
	{
		iter->second->release();
		_items.erase(iter);
		return true;
	}

	return false;
}

Item* Bag::getItem(int itemID)
{
	std::map<int, Item*>::iterator iter = _items.find(itemID);
	if (iter != _items.end())
	{
		return iter->second;
	}

	return nullptr;
}

void Bag::removeAllItems()
{
	std::map<int, Item*>::iterator iter = _items.begin();
	while (iter != _items.end())
	{
		iter->second->release();
		iter++;
	}

	_items.clear();
}

int Bag::count()
{
	return _items.size();
}
