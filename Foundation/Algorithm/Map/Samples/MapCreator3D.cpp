#include "MapCreator3D.h"

alg::MapModule3D::MapModule3D()
{

}

alg::MapModule3D::~MapModule3D()
{

}

void alg::MapModule3D::setDirectionSlot(MapDirection3D eDirection, uint32_t slotIndex)
{
	this->getSlot()->addSlot((uint32_t)eDirection, slotIndex);
}

void alg::MapModule3D::setLeftSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection3D::LEFT, slotIndex);
}

void alg::MapModule3D::setRightSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection3D::RIGHT, slotIndex);
}

void alg::MapModule3D::setTopSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection3D::Top, slotIndex);
}

void alg::MapModule3D::setBottomSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection3D::Bottom, slotIndex);
}

void alg::MapModule3D::setFrontSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection3D::FRONT, slotIndex);
}

void alg::MapModule3D::setBackSlot(uint32_t slotIndex)
{
	this->setDirectionSlot(MapDirection3D::BACK, slotIndex);
}

