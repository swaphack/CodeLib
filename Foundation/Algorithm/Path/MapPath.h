#pragma once

#include <list>
#include "mathlib.h"

namespace alg
{
	class Map;

	class MapPath
	{
	public:
		static bool findWayByAStar(const Map* map, const math::Vector3& src, const math::Vector3& dest, std::list<math::Vector3>& path);

	};
}