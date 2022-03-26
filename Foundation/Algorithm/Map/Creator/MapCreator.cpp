#include "MapCreator.h"
#include "Map/Base/MapProtocol.h"

alg::map::MapCreator::MapCreator(uint32_t slotCount, IMapObjectCreate* moduleCreate)
{
	_mapAssets = new MapAssets(slotCount, moduleCreate);
}

alg::map::MapCreator::~MapCreator()
{
	delete _mapAssets;
}
void alg::map::MapCreator::setSeed(uint32_t seed)
{
	_seed = seed;
}

uint32_t alg::map::MapCreator::getSeed() const
{
	return _seed;
}

alg::map::MapAssets* alg::map::MapCreator::getMapAssets() const
{
	return _mapAssets;
}

bool alg::map::MapCreator::getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const
{
	return false;
}

inline bool alg::map::MapCreator::isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const
{
	return false;
}

const alg::map::Module* alg::map::MapCreator::getModule(uint32_t moduleID) const
{
	if (_mapAssets == nullptr)
	{
		return nullptr;
	}

	return _mapAssets->getModule(moduleID);
}

void alg::map::MapCreator::setMapAssets(const MapAssets* assets)
{
	if (_mapAssets != nullptr) delete _mapAssets;
	_mapAssets = (MapAssets*)assets;
}

bool alg::map::MapCreator::create(MapProtocol* map, WFCAlgorithm* alg)
{
	if (map == nullptr || alg == nullptr)
	{
		return false;
	}

	sys::Random::setSeed(_seed);

	MultiState states;
	for (const auto& item : _mapAssets->getAllModules())
	{
		states.add(item.first);
	}
	alg->initMap(map->getCellCount(), states);
	return alg->autoFillMap(map, this);
}

bool alg::map::MapCreator::getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const
{
	if (map == nullptr)
	{
		return false;
	}
	if (nIndex >= map->getCellCount())
	{
		return false;
	}
	CombineSlots slots;
	if (!getMatchPointSlots(map, nIndex, slots))
	{
		return false;
	}

	if (!slots.empty())
	{
		return _mapAssets->findModule(slots, modules);
	}
	else
	{
		return true;
	}
}
