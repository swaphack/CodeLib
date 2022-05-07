#include "CubeMapCreator.h"
#include "Map/Assets/Slots.h"
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

alg::map::CubeMapModuleCreate::CubeMapModuleCreate()
{
}
alg::map::CubeMapModuleCreate::~CubeMapModuleCreate()
{
}


alg::map::CubeMapCreator::CubeMapCreator(int slotCount, uint32_t width, uint32_t height, uint32_t depth)
	:MapCreator(slotCount, new CubeMapModuleCreate())
{
	this->initCubeMap(width, height, depth);
}

alg::map::CubeMapCreator::~CubeMapCreator() 
{}

void alg::map::CubeMapCreator::initCubeMap(uint32_t width, uint32_t height, uint32_t depth)
{
	_width = width;
	_height = height;
	_depth = depth;
}

bool alg::map::CubeMapCreator::getMatchModules(uint32_t nIndex, std::vector<uint32_t>& modules)
{
	return false;
}

bool alg::map::CubeMapCreator::isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID)
{
	return false;
}

bool alg::map::CubeMapCreator::create()
{
	return false;
}
