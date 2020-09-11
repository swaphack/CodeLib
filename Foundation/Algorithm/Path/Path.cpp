#include "Path.h"
#include "Map/Map.h"
alg::Path::Path()
{

}

alg::Path::~Path()
{

}

void alg::Path::addDistance(const Map* map, uint32_t fromIndex, uint32_t toIndex)
{
	if (map == nullptr)
	{
		return;
	}

	auto point0 = map->getPoint(fromIndex);
	auto point1 = map->getPoint(toIndex);
	if (point0 == nullptr || point1 == nullptr)
	{
		return;
	}

	float distance = math::Vector3::distance(*point0, *point1);
	std::string mark0 = getCString("%d, %d", fromIndex, toIndex);
	std::string mark1 = getCString("%d, %d", toIndex, fromIndex);

	_distances[mark0] = distance;
	_distances[mark1] = distance;
}

float alg::Path::getDistance(const Map* map, uint32_t fromIndex, uint32_t toIndex)
{
	if (map == nullptr)
	{
		return -1;
	}

	std::string mark0 = getCString("%d, %d", fromIndex, toIndex);
	auto it = _distances.find(mark0);
	if (it == _distances.end())
	{
		this->addDistance(map, fromIndex, toIndex);
		return _distances[mark0];
	}
	else
	{
		return it->second;
	}
}

