#include "RectMapCreator.h"

alg::map::RectModule::RectModule()
{

}

alg::map::RectModule::~RectModule()
{

}

void alg::map::RectModule::setSlot(RectModuleDirection eDirection, uint32_t slotIndex)
{
	this->getModuleSlot()->addSlot((uint32_t)eDirection, slotIndex);
}

uint32_t alg::map::RectModule::getSlot(RectModuleDirection eDirection)
{
	return this->getModuleSlot()->getSlot((uint32_t)eDirection);
}

void alg::map::RectModule::setLeftSlot(uint32_t slotIndex)
{
	this->setSlot(RectModuleDirection::LEFT, slotIndex);
}

void alg::map::RectModule::setRightSlot(uint32_t slotIndex)
{
	this->setSlot(RectModuleDirection::RIGHT, slotIndex);
}

void alg::map::RectModule::setUpSlot(uint32_t slotIndex)
{
	this->setSlot(RectModuleDirection::UP, slotIndex);
}

void alg::map::RectModule::setDownSlot(uint32_t slotIndex)
{
	this->setSlot(RectModuleDirection::DOWN, slotIndex);
}
