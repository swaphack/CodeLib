#include "MapCreator2D.h"

alg::MapModule2D::MapModule2D()
{

}

alg::MapModule2D::~MapModule2D()
{

}

void alg::MapModule2D::setDirectionSlot(MapDirection2D eDirection, uint32_t slotIndex)
{
	this->getSlot()->addSlot((uint32_t)eDirection, slotIndex);
}

void alg::MapModule2D::setLeftSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection2D::LEFT, slotIndex);
}

void alg::MapModule2D::setRightSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection2D::RIGHT, slotIndex);
}

void alg::MapModule2D::setUpSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection2D::UP, slotIndex);
}

void alg::MapModule2D::setDownSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection2D::DOWN, slotIndex);
}
