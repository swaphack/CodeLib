#pragma once
#include "MapCell.h"
#include <vector>

namespace ai
{
	class IMap
	{
	public:
		void findWayFromTo(const MapCell* src, const MapCell* dest, std::vector<MapCell*>& path);
	};
}