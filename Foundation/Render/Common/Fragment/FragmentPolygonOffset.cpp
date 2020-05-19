#include "FragmentPolygonOffset.h"
#include "Graphic/import.h"

render::FragmentPolygonOffset::FragmentPolygonOffset()
	:FragmentHandle(FragmentType::POLYGON_OFFSET)
{
	_offset.t1 = 0;
	_offset.t2 = 1;
}

render::FragmentPolygonOffset::~FragmentPolygonOffset()
{

}

void render::FragmentPolygonOffset::setOffsetType(PolygonOffsetType type)
{
	this->setEnableMode((EnableMode)type);
}

void render::FragmentPolygonOffset::setOffset(float factor, float units)
{
	_offset.t1 = factor;
	_offset.t2 = units;
}

void render::FragmentPolygonOffset::update()
{
	GLState::setPolygonOffset(_offset.t1, _offset.t2);
}

