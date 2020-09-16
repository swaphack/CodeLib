#include "Path.h"
#include "Map/Base/Map.h"
alg::Path::Path()
{

}

alg::Path::~Path()
{

}

void alg::Path::addDistance(const MapProtocol* map, uint32_t fromIndex, uint32_t toIndex)
{
	if (map == nullptr)
	{
		return;
	}

	float distance = map->getDistance(fromIndex, toIndex);
	if (distance == -1)
	{
		return;
	}
	std::string mark0 = getCString("%d, %d", fromIndex, toIndex);
	std::string mark1 = getCString("%d, %d", toIndex, fromIndex);

	_distances[mark0] = distance;
	_distances[mark1] = distance;
}

float alg::Path::getDistance(const MapProtocol* map, uint32_t fromIndex, uint32_t toIndex)
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

