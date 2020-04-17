#pragma once

#include <list>

namespace alg
{

	class MapNode;

	class MapPath
	{
	public:
		bool findWayByAStar(const MapNode* src, const MapNode* dest, std::list<MapNode*>& path);

	};
}