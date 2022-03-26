#include "PointMap.h"


alg::map::PointMapCellCreate::~PointMapCellCreate() {}

alg::map::MapObject* alg::map::PointMapCellCreate::create()
{
	return new PointMapCell();
}

alg::map::PointMap::PointMap() 
{
	_mapCell.setCreateFunc(new PointMapCellCreate());
}

alg::map::PointMap::~PointMap()
{
}

float alg::map::PointMap::getDistance(uint32_t srcIndex, uint32_t toIndex) const
{
	auto point0 = getPoint(srcIndex);
	auto point1 = getPoint(toIndex);
	if (point0 == nullptr || point1 == nullptr)
	{
		return -1;
	}

	return math::Vector3::distance(*point0, *point1);
}

int32_t alg::map::PointMap::addPoint(const math::Vector3& point)
{
	PointMapCell* mp = this->createCell<PointMapCell>();
	if (mp)
	{
		mp->setPosition(point);
		return mp->getMapObjectID();
	}
	return -1;
}

const math::Vector3* alg::map::PointMap::getPoint(uint32_t nIndex) const
{
	auto mp = this->getCell(nIndex);
	if (mp)
	{
		return &mp->getPosition();
	}

	return nullptr;
}

