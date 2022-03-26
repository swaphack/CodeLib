#include "MapAssets.h"

alg::map::MapModuleCreate::~MapModuleCreate() {}

alg::map::MapObject* alg::map::MapModuleCreate::create()
{
	return new alg::map::Module();
}

alg::map::MapAssets::MapAssets(int nSlotCount, IMapObjectCreate* moduleCreate)
{
	_mapModule.setCreateFunc(moduleCreate);
	_mapModule.increaseID();
	_mapSlotRule.init(nSlotCount);
}

alg::map::MapAssets::~MapAssets()
{

}


alg::map::Module* alg::map::MapAssets::createModule(uint32_t resID, const std::map<uint32_t, uint32_t>& slots)
{
	auto ptr = _mapModule.create();
	if (ptr == nullptr) return nullptr;

	auto pModule = dynamic_cast<Module*>(ptr);
	if (pModule)
	{
		pModule->setResourceID(resID);
		pModule->getModuleSlot()->setSlots(slots);

		for (auto item : slots)
		{
			_mapModuleTag[item.first].insert(pModule->getMapObjectID());
		}
	}
	else
	{
		delete ptr;
	}
	return pModule;
}
void alg::map::MapAssets::removeAllModules()
{
	_mapModule.removeAllObjects();
}

uint32_t alg::map::MapAssets::getModuleCount() const
{
	return _mapModule.getObjectCount();
}


const alg::map::Module* alg::map::MapAssets::getModule(uint32_t nIndex) const
{
	auto pObject = _mapModule.getObject(nIndex);
	return (Module*)pObject;
}

std::map<uint32_t, alg::map::Module*> alg::map::MapAssets::getAllModules() const
{
	auto allObjects = _mapModule.getAllObjects();
	std::map<uint32_t, alg::map::Module*> mapModules;
	for (auto& item : allObjects)
	{
		mapModules[item.first] = (Module*)item.second;
	}
	return mapModules;
}
void alg::map::MapAssets::addMatchRule(uint32_t key, const std::vector<uint32_t>& targets)
{
	_mapSlotRule.addRelation(key, targets, 1);
}

void alg::map::MapAssets::removeAllMatchRules()
{
	_mapSlotRule.resetAllRelations(0);
}

bool alg::map::MapAssets::getMatchSlots(uint32_t slotIndex, std::vector<uint32_t>& relativeSlots) const
{
	return _mapSlotRule.getRelations(slotIndex, 1, relativeSlots);
}

const alg::map::SlotRule& alg::map::MapAssets::getSlotRule() const
{
	return _mapSlotRule;
}

bool alg::map::MapAssets::hasRelation(uint32_t src, uint32_t dest, int value)
{
	return _mapSlotRule.hasRelation(src, dest, value);
}

bool alg::map::MapAssets::findModule(const Slots& conditionSlots, std::vector<uint32_t>& modules)
{
	return findModule(conditionSlots.getAllSlots(), modules);
}

bool alg::map::MapAssets::findModule(const CombineSlots& conditionSlots, std::vector<uint32_t>& modules)
{
	return findModule(conditionSlots.getAllSlots(), modules);
}

bool alg::map::MapAssets::findModule(const std::map<uint32_t, std::set<uint32_t>>& conditionSlots, std::vector<uint32_t>& modules)
{
	int32_t target = -1;
	int32_t count = -1;

	// 查询数据量最小的组
	for (const auto& item : conditionSlots)
	{
		auto it = _mapModuleTag.find(item.first);
		if (it == _mapModuleTag.end() || it->second.size() == 0)
		{// 无相关匹配对象
			return false;
		}

		if (target == -1 || count > (int)(it->second.size()))
		{
			target = item.first;
			count = it->second.size();
		}
	}

	if (target == -1)
	{
		return false;
	}

	// 查询匹配的模块
	auto setData = _mapModuleTag[target];
	for (const auto& item : setData)
	{
		auto pModule = getModule(item);
		if (pModule->getModuleSlot()->matchSlots(conditionSlots))
		{
			modules.push_back(item);
		}
	}
	return modules.size() > 0;
}

bool alg::map::MapAssets::findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules)
{
	uint32_t target = 0;
	uint32_t count = 0;

	// 查询数据量最小的组
	for (const auto& item : conditionSlots)
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

	// 查询匹配的模块
	auto setData = _mapModuleTag[target];
	for (const auto& item : setData)
	{
		auto pModule = getModule(item);
		if (pModule->getModuleSlot()->matchSlots(conditionSlots))
		{
			modules.push_back(item);
		}
	}

	return modules.size() > 0;
}


