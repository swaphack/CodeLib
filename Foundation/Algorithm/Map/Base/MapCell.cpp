#include "MapCell.h"

alg::MapCell::MapCell()
{

}

alg::MapCell::~MapCell()
{

}

void alg::MapCell::setModuleIndex(uint32_t moduleIndex)
{
	_moduleIndex = moduleIndex;
}

uint32_t alg::MapCell::getModuldeIndex() const
{
	return _moduleIndex;
}

void alg::MapCell::setPosition(const math::Vector3& pos)
{
	_position = pos;
}

const math::Vector3& alg::MapCell::getPosition() const
{
	return _position;
}

