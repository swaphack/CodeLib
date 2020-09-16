#include "MapCreator2D.h"

alg::MapModule2D::MapModule2D()
{

}


alg::MapModule2D::~MapModule2D()
{

}

void alg::MapModule2D::setDirectionSlot(Map2DDirection eDirection, uint32_t slotIndex)
{
	this->getSlot()->set((uint32_t)eDirection, slotIndex);
}

void alg::MapModule2D::setLeftSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(Map2DDirection::LEFT, slotIndex);
}

void alg::MapModule2D::setRightSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(Map2DDirection::RIGHT, slotIndex);
}

void alg::MapModule2D::setUpSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(Map2DDirection::UP, slotIndex);
}

void alg::MapModule2D::setDownSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(Map2DDirection::DOWN, slotIndex);
}

//////////////////////////////////////////////////////////////////////////

alg::MapCreator2D::MapCreator2D()
{

}

alg::MapCreator2D::~MapCreator2D()
{

}

void alg::MapCreator2D::setMapSize(uint32_t width, uint32_t height)
{
	_mapWidth = width;
	_mapHeight = height;
}

uint32_t alg::MapCreator2D::getWidth() const
{
	return _mapWidth;
}

uint32_t alg::MapCreator2D::getHeight() const
{
	return _mapHeight;
}
