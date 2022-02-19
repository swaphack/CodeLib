#include "TerrianHelper.h"
#include "system.h"

void alg::mesh::TerrianHelper::getRange(const math::Vector3& start, const math::Vector3& end, math::Vector3& min, math::Vector3& max)
{
	min = math::Vector3(MIN(start.getX(), end.getX()), MIN(start.getY(), end.getY()), MIN(start.getZ(), end.getZ()));
	max = math::Vector3(MAX(start.getX(), end.getX()), MAX(start.getY(), end.getY()), MAX(start.getZ(), end.getZ()));
}

math::Vector3 alg::mesh::TerrianHelper::getRandomPosition(math::Vector3 start, math::Vector3 end)
{
    math::Vector3 value;
    value.setX(sys::Random::getNumber(start.getX(), end.getX()));
    value.setY(sys::Random::getNumber(start.getY(), end.getY()));
    value.setZ(sys::Random::getNumber(start.getZ(), end.getZ()));
    return value;
}
