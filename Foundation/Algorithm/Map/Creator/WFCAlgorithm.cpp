#include "WFCAlgorithm.h"
#include "Map/Base/MapProtocol.h"
#include "Map/Base/Module.h"
#include "Map/Base/MapCell.h"
#include "MapCreator.h"

alg::map::WFCAlgorithm::WFCAlgorithm()
{
}

alg::map::WFCAlgorithm::~WFCAlgorithm()
{
}

void alg::map::WFCAlgorithm::initMap(uint32_t pointCount, const MultiState& states)
{
	_pointCount = pointCount;
	_moduleStates = states;
	for (size_t i = 0; i < pointCount; i++)
	{
		_mapPoint[i] = 0;
		_unFillPoint.insert(i);
		_pointModules[i] = states;
	}
}

bool alg::map::WFCAlgorithm::autoFillMap(MapProtocol* map, CreateMapProtocol* creator)
{
	// 先采用随机方法，尽可能填充
	if (!randomFillPoint(map, creator))
	{
		return false;
	}
	

	// 随机选择一个已填充的点，从他周围开始查找
	do
	{
		if (_filledPoint.empty())
		{// 填充为空，失败
			return false;
		}

		if (_unFillPoint.empty())
		{// 填充完毕
			return true;
		}

		uint32_t nIndex = 0;
		if (!getRandomFilledPoint(nIndex))
		{
			return false;
		}

		if (!roundFillPoint(nIndex, map, creator))
		{
			return false;
		}

	} while (!_unFillPoint.empty());
	

	return true;
}

bool alg::map::WFCAlgorithm::randomFillPoint(MapProtocol* map, CreateMapProtocol* creator)
{
	if (map == nullptr || creator == nullptr)
	{
		return false;
	}
	bool canFillEmpty = false;
	uint32_t nIndex = 0;

	if (!getRandomUnfillPoint(nIndex))
	{
		return false;
	}

	std::vector<uint32_t> modules;
	if (!creator->getFillPointModules(map, nIndex, modules))
	{
		return false;
	}

	if (modules.empty())
	{
		modules = _pointModules[nIndex].getAllStates();
	}
	else
	{
		_pointModules[nIndex].set(modules);
	}

	if (modules.empty())
	{
		return false;
	}

	uint32_t idx = sys::Random::getNumber(modules.size() - 1);
	uint32_t moduleID = modules[idx];
	_pointModules[nIndex].remove(moduleID);
	setPoint(map, nIndex, moduleID);

	return true;
}

// 绕指定目标周围开始填充

bool alg::map::WFCAlgorithm::roundFillPoint(uint32_t nIndex, MapProtocol* map, CreateMapProtocol* creator)
{
	if (map == nullptr || creator == nullptr)
	{
		return false;
	}

	uint32_t srcModuleID = 0;
	if (!getModuleID(nIndex, srcModuleID))
	{
		return false;
	}

	std::vector<uint32_t> neighboors;
	if (!map->findNeighborCells(nIndex, neighboors))
	{
		return false;
	}

	std::vector<uint32_t> modules;
	if (!creator->getFillPointModules(map, nIndex, modules))
	{
		return false;
	}

	if (modules.empty())
	{
		modules = _pointModules[nIndex].getAllStates();
	}

	uint32_t idx = sys::Random::getNumber(modules.size() - 1);
	uint32_t moduleID = modules[idx];
	_pointModules[nIndex].remove(moduleID);
	setPoint(map, nIndex, moduleID);

	for (const auto item : neighboors)
	{
		uint32_t nModuleID = _mapPoint[item];

		// 未分配的
		if (nModuleID == 0)
		{
			std::vector<uint32_t> modules;
			if (!creator->getFillPointModules(map, item, modules))
			{
				resetPoint(map, item);
				return false;
			}
			if (!modules.empty())
			{
				_pointModules[item].set(modules);
			}
		}
		else
		{// 回溯

		}
	}

	return true;
}

/**
*	设置点信息
*/

void alg::map::WFCAlgorithm::setPoint(MapProtocol* map, uint32_t index, uint32_t moduleID)
{
	if (index >= _pointCount)
	{
		return;
	}
	auto pCell = map->getCell(index);
	if (pCell != nullptr)
	{
		pCell->setModuleID(moduleID);
	}
	_unFillPoint.erase(index);
	_filledPoint.insert(index);
	_mapPoint[index] = moduleID;
}

/**
*	重置点信息
*/

void alg::map::WFCAlgorithm::resetPoint(MapProtocol* map, uint32_t index)
{
	if (index >= _pointCount)
	{
		return;
	}
	auto pCell = map->getCell(index);
	if (pCell != nullptr)
	{
		pCell->setModuleID(0);
	}
	_unFillPoint.insert(index);
	_filledPoint.erase(index);
	_mapPoint[index] = 0;
	_pointModules[index] = _moduleStates;
}

/**
*	是否全部已设置
*/

bool alg::map::WFCAlgorithm::isFinish()
{
	return _unFillPoint.empty();
}

const std::map<uint32_t, uint32_t>& alg::map::WFCAlgorithm::getResult()
{
	return _mapPoint;
}

/**
*	随机获取一个未填充点
*/

bool alg::map::WFCAlgorithm::getRandomUnfillPoint(uint32_t& index)
{
	if (isFinish())
	{
		return false;
	}

	uint32_t idx = sys::Random::getNumber(_unFillPoint.size() - 1);
	std::set<uint32_t>::iterator it = _unFillPoint.begin();
	std::advance(it, idx);
	index = *it;
	return true;
}

/**
*	随机获取一个已填充点
*/

bool alg::map::WFCAlgorithm::getRandomFilledPoint(uint32_t& index)
{
	if (isFinish())
	{
		return false;
	}

	int32_t idx = -1;
	int32_t count = 0;

	for (auto item : _unFillPoint)
	{
		uint32_t i = item;
		uint32_t j = _pointModules[i].getCount();
		if (idx == -1 || count > j)
		{
			idx = i;
			count = j;
		}
	}

	if (idx == -1)
	{
		return false;
	}

	index = idx;
	return true;
}

/**
*	获取指定位置的模块编号
*/

const alg::map::Module* alg::map::WFCAlgorithm::getModule(CreateMapProtocol* creator, uint32_t index) const
{
	auto it1 = _mapPoint.find(index);
	if (it1 == _mapPoint.end())
	{
		return nullptr;
	}
	uint32_t moduleID = it1->second;

	return creator->getModule(index);
}

/**
*	获取指定位置的模块编号
*/

bool alg::map::WFCAlgorithm::getModuleID(uint32_t index, uint32_t& moduleID) const
{
	auto it1 = _mapPoint.find(index);
	if (it1 == _mapPoint.end())
	{
		return false;
	}
	moduleID = it1->second;
	return true;
}
