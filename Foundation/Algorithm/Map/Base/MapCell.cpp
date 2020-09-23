#include "MapCell.h"

alg::map::MapCell::MapCell()
{

}

alg::map::MapCell::~MapCell()
{

}

void alg::map::MapCell::setModuleID(uint32_t moduleID)
{
	_moduleID = moduleID;
}

uint32_t alg::map::MapCell::getModuldeID() const
{
	return _moduleID;
}

void alg::map::MapCell::setPosition(const math::Vector3& pos)
{
	_position = pos;
}

const math::Vector3& alg::map::MapCell::getPosition() const
{
	return _position;
}

