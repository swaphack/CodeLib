#include "MapCreator.h"
#include "MapSlot.h"

alg::MapCreator::MapCreator()
{

}

alg::MapCreator::~MapCreator()
{

}

alg::MapModule* alg::MapCreator::createModule(const std::map<uint32_t, uint32_t>& slots)
{
	auto ptr = _mapModule.create();
	if (ptr)
	{
		ptr->getSlot()->set(slots);

		for (auto item : slots)
		{
			_mapModuleTag[item.first].insert(ptr->getObjectIndex());
		}
	}

	return ptr;
}

void alg::MapCreator::removeAllModules()
{
	_mapModule.removeAllObjects();
}

uint32_t alg::MapCreator::getModuleCount() const
{
	return _mapModule.getObjectCount();
}

const alg::MapModule* alg::MapCreator::getModule(uint32_t nIndex) const
{
	return _mapModule.getObject(nIndex);
}

void alg::MapCreator::removeAllSlotRules()
{
	_mapSlotRule.clear();
}

uint32_t alg::MapCreator::getSlotRuleCount() const
{
	return _mapSlotRule.size();
}

bool alg::MapCreator::getSlotRule(uint32_t nSlotIndex, std::vector<uint32_t>& slots) const
{
	auto it = _mapSlotRule.find(nSlotIndex);
	if (it == _mapSlotRule.end())
	{
		return false;
	}

	auto mp = it->second.getObject(0);
	if (mp == nullptr)
	{
		return false;
	}

	slots = mp->getAllRelations();

	return slots.size() > 0;
}

bool alg::MapCreator::findModule(const MapSlot& conditionSlots, std::vector<uint32_t>& modules)
{
	return findModule(conditionSlots.getSlots(), modules);
}

bool alg::MapCreator::findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules)
{
	
	uint32_t target = 0;
	uint32_t count = 0;

	// 查询数据量最小的组
	for (auto item : conditionSlots)
	{
		auto it = _mapModuleTag.find(item.first);
		if (it == _mapModuleTag.end() || it->second.size() == 0)
		{// 无相关匹配对象
			return false;
		}

		if (target == 0 || count > it->second.size())
		{
			target = item.first;
			count = it->second.size();
		}
	}

	// 查询数据量最小的组
	auto setData = _mapModuleTag[target];
	for (auto item : setData)
	{
		auto pModule = getModule(item);
		if (pModule->getSlot()->match(conditionSlots))
		{
			modules.push_back(item);
		}
	}

	return modules.size() > 0;
}
