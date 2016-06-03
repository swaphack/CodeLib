#include "Item.h"

using namespace slg;


Item::Item()
:_itemID(0)
, _itemType(0)
{

}

Item::~Item()
{

}

int Item::getItemID()
{
	return _itemID;
}

void Item::setItemID(int itemID)
{
	_itemID = itemID;
}

int Item::getItemType()
{
	return _itemType;
}

void Item::setItemType(int itemType)
{
	_itemType = itemType;
}
