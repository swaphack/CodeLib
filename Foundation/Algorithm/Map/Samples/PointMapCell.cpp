#include "PointMapCell.h"
#include "mathlib.h"

alg::PointMapCell::PointMapCell()
{

}

alg::PointMapCell::~PointMapCell()
{

}

void alg::PointMapCell::setPosition(const math::Vector3& pos)
{
	_position = pos;
}

const math::Vector3& alg::PointMapCell::getPosition() const
{
	return _position;
}
