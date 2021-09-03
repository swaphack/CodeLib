#include "CubeMapCreator.h"
#include "Map/Base/Slots.h"
alg::map::CubeMapModule::CubeMapModule()
{

}

alg::map::CubeMapModule::~CubeMapModule()
{

}

void alg::map::CubeMapModule::setSlot(CubeModuleDirection eDirection, uint32_t slotIndex)
{
	this->getModuleSlot()->addSlot((uint32_t)eDirection, slotIndex);
}

uint32_t alg::map::CubeMapModule::getSlot(CubeModuleDirection eDirection)
{
	return this->getModuleSlot()->getSlot((uint32_t)eDirection);
}

void alg::map::CubeMapModule::setLeftSlot(uint32_t slotIndex)
{
	this->setSlot(CubeModuleDirection::LEFT, slotIndex);
}

void alg::map::CubeMapModule::setRightSlot(uint32_t slotIndex)
{
	this->setSlot(CubeModuleDirection::RIGHT, slotIndex);
}

void alg::map::CubeMapModule::setTopSlot(uint32_t slotIndex)
{
	this->setSlot(CubeModuleDirection::Top, slotIndex);
}

void alg::map::CubeMapModule::setBottomSlot(uint32_t slotIndex)
{
	this->setSlot(CubeModuleDirection::Bottom, slotIndex);
}

void alg::map::CubeMapModule::setFrontSlot(uint32_t slotIndex)
{
	this->setSlot(CubeModuleDirection::FRONT, slotIndex);
}

void alg::map::CubeMapModule::setBackSlot(uint32_t slotIndex)
{
	this->setSlot(CubeModuleDirection::BACK, slotIndex);
}

