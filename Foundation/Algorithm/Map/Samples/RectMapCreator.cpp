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

alg::map::RectModuleCreate::RectModuleCreate()
{
}

alg::map::RectModuleCreate::~RectModuleCreate()
{
}

alg::map::MapObject* alg::map::RectModuleCreate::create()
{
	return new RectModule();
}

alg::map::RectMapCreator::RectMapCreator(int slotCount, uint32_t width, uint32_t height)
	:MapCreator(slotCount, new RectModuleCreate())
{
	_width = width;
	_height = height;
}

alg::map::RectMapCreator::~RectMapCreator() 
{
}

bool alg::map::RectMapCreator::getSlots(const MapCell* cell, RectModuleDirection dir, CombineSlots& slots) const
{
	if (cell == nullptr)
	{
		return false;
	}

	uint32_t nModuleID = cell->getModuldeID();
	if (nModuleID == 0)
	{
		return false;
	}

	auto pModule = getModule(nModuleID);
	if (pModule == nullptr)
	{
		return false;
	}

	RectModuleDirection reverseDir = RectModuleDirection::LEFT;
	switch (dir)
	{
	case alg::map::RectModuleDirection::LEFT:
		reverseDir = RectModuleDirection::RIGHT;
		break;
	case alg::map::RectModuleDirection::RIGHT:
		reverseDir = RectModuleDirection::LEFT;
		break;
	case alg::map::RectModuleDirection::UP:
		reverseDir = RectModuleDirection::DOWN;
		break;
	case alg::map::RectModuleDirection::DOWN:
		reverseDir = RectModuleDirection::UP;
		break;
	default:
		break;
	}

	uint32_t nTargetSlot = pModule->getModuleSlot()->getSlot((uint32_t)reverseDir);
	std::vector<uint32_t> relations;
	if (_mapAssets->getMatchSlots(nTargetSlot, relations))
	{
		slots.addSlots((uint32_t)dir, relations);
		return true;
	}

	return false;
}

bool alg::map::RectMapCreator::getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const
{
	auto pCell = map->getCell(nIndex);
	if (pCell == nullptr)
	{
		return false;
	}

	uint32_t i = nIndex / _width;
	uint32_t j = nIndex % _width;

	RectModule module;
	if (j > 0)
	{
		auto pLeftCell = map->getCell(nIndex - 1);

		if (pLeftCell != nullptr && pLeftCell->getModuldeID() > 0)
		{// ×ó±ß
			getSlots(pLeftCell, RectModuleDirection::LEFT, slots);

		}
	}
	if (j < _width - 1)
	{
		auto pRightCell = map->getCell(nIndex + 1);
		if (pRightCell != nullptr && pRightCell->getModuldeID() > 0)
		{// ÓÒ±ß
			getSlots(pRightCell, RectModuleDirection::RIGHT, slots);
		}
	}
	if (i > 0)
	{
		auto pDownCell = map->getCell(nIndex - _width);
		if (pDownCell != nullptr && pDownCell->getModuldeID() > 0)
		{// ÓÒ±ß
			getSlots(pDownCell, RectModuleDirection::DOWN, slots);
		}
	}

	if (i < _height - 1)
	{
		auto pUpCell = map->getCell(nIndex + _width);
		if (pUpCell != nullptr && pUpCell->getModuldeID() > 0)
		{// ÓÒ±ß
			getSlots(pUpCell, RectModuleDirection::UP, slots);
		}
	}
	return true;
}

bool alg::map::RectMapCreator::isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const
{
	RectModule* pSrcModule = (RectModule*)getModule(srcModuleID);
	RectModule* pDestModule = (RectModule*)getModule(destModuleID);
	if (pSrcModule == nullptr || pDestModule == nullptr)
	{
		return true;
	}

	std::map<uint32_t, RectModule*> mapModule;
	mapModule[srcIndex] = pSrcModule;
	mapModule[destIndex] = pDestModule;

	uint32_t minIndex = MIN(srcIndex, destIndex);
	uint32_t maxIndex = MAX(srcIndex, destIndex);

	uint32_t minI = minIndex / _width;
	uint32_t minJ = minIndex % _width;

	uint32_t maxI = maxIndex / _width;
	uint32_t maxJ = maxIndex % _width;

	// ×óÓÒ¹ØÏµ
	if (minI == maxI && minJ + 1 == maxJ)
	{
		auto pLeftModule = mapModule[minIndex];
		auto pRightModule = mapModule[maxIndex];

		if (_mapAssets->hasRelation(pLeftModule->getSlot(RectModuleDirection::RIGHT),
			pRightModule->getSlot(RectModuleDirection::LEFT)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// ÉÏÏÂ¹ØÏµ
	if (minJ == maxJ && minI + 1 == maxI)
	{
		auto pBottomModule = mapModule[minIndex];
		auto pTopModule = mapModule[maxIndex];

		if (_mapAssets->hasRelation(pBottomModule->getSlot(RectModuleDirection::UP),
			pTopModule->getSlot(RectModuleDirection::DOWN)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return true;
}
