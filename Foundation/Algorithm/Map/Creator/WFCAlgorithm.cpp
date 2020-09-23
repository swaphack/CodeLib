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
	// �Ȳ���������������������
	if (!randomFillPoint(map, creator))
	{
		return false;
	}
	

	// ���ѡ��һ�������ĵ㣬������Χ��ʼ����
	do
	{
		if (_filledPoint.empty())
		{// ���Ϊ�գ�ʧ��
			return false;
		}

		if (_unFillPoint.empty())
		{// ������
			return true;
		}

		uint32_t nIndex = 0;
		if (!getRandomFilledPoint(nIndex))
		{
			return false;
		}

		roundFillPoint(nIndex, map, creator);

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

	if (!getRandomUnFillPoint(nIndex))
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

// ��ָ��Ŀ����Χ��ʼ���

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

	for (const auto item : neighboors)
	{
		std::vector<uint32_t> modules;
		if (!creator->getFillPointModules(map, item, modules))
		{
			resetPoint(map, item);
			return false;
		}
		else
		{
			modules = _pointModules[item].getAllStates();
		}

		if (modules.empty())
		{
			resetPoint(map, item);
			return false;
		}

		auto it = _mapPoint.find(item);
		if (it != _mapPoint.end())
		{
			auto it1 = std::find(modules.begin(), modules.end(), it->second);
			if (it1 != modules.end())
			{
				continue;
			}
			else
			{
				resetPoint(map, item);
				_pointModules[item].set(modules);
			}
		}
		else
		{
			_pointModules[item].set(modules);
		}

		uint32_t idx = sys::Random::getNumber(modules.size() - 1);
		uint32_t moduleID = modules[idx];
		_pointModules[item].remove(moduleID);
		setPoint(map, item, moduleID);
	}

	return true;
}

/**
*	���õ���Ϣ
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

	_mapPoint[index] = moduleID;
	_unFillPoint.erase(index);
	_filledPoint.insert(index);
}

/**
*	���õ���Ϣ
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

	uint32_t value = _mapPoint[index];
	_unFillPoint.insert(index);
	_filledPoint.erase(index);
	_pointModules[index] = _moduleStates;
}

/**
*	�Ƿ�ȫ��������
*/

bool alg::map::WFCAlgorithm::isFinish()
{
	return _unFillPoint.empty();
}

/**
*	�����ȡһ��δ����
*/

bool alg::map::WFCAlgorithm::getRandomUnFillPoint(uint32_t& index)
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
*	�����ȡһ��������
*/

bool alg::map::WFCAlgorithm::getRandomFilledPoint(uint32_t& index)
{
	if (isFinish())
	{
		return false;
	}

	int32_t idx = -1;
	int32_t count = 0;

	for (size_t i = 0; i < _pointModules.size(); i++)
	{
		if (idx == -1 || count > _pointModules[i].getCount() )
		{
			idx = i;
			count = _pointModules[i].getCount();
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
*	��ȡָ��λ�õ�ģ����
*/

const alg::map::Module* alg::map::WFCAlgorithm::getModule(CreateMapProtocol* creator, uint32_t index) const
{
	auto it = _filledPoint.find(index);
	if (it == _filledPoint.end())
	{
		return nullptr;
	}

	auto it1 = _mapPoint.find(index);
	if (it1 == _mapPoint.end())
	{
		return nullptr;
	}
	uint32_t moduleID = it1->second;

	return creator->getModule(index);
}

/**
*	��ȡָ��λ�õ�ģ����
*/

bool alg::map::WFCAlgorithm::getModuleID(uint32_t index, uint32_t& moduleID) const
{
	auto it = _filledPoint.find(index);
	if (it == _filledPoint.end())
	{
		return false;
	}
	auto it1 = _mapPoint.find(index);
	if (it1 == _mapPoint.end())
	{
		return nullptr;
	}
	moduleID = it1->second;
	return true;
}
