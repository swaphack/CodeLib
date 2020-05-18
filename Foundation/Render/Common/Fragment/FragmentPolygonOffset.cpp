#include "FragmentPolygonOffset.h"
#include "Graphic/import.h"

render::FragmentPolygonOffset::FragmentPolygonOffset()
{
	_fragmentType = FragmentType::POLYGON_OFFSET;

	_offsetType = PolygonOffsetType::POLYGON_OFFSET_FILL;
	_offset.t1 = 0;
	_offset.t2 = 1;
}

render::FragmentPolygonOffset::~FragmentPolygonOffset()
{

}

void render::FragmentPolygonOffset::setOffsetType(PolygonOffsetType type)
{
	_offsetType = type;
}

void render::FragmentPolygonOffset::setOffset(float factor, float units)
{
	_offset.t1 = factor;
	_offset.t2 = units;
}

void render::FragmentPolygonOffset::begin()
{
	GLState::enable((EnableModel)_offsetType);
}

void render::FragmentPolygonOffset::update()
{
	GLState::setPolygonOffset(_offset.t1, _offset.t2);
}

void render::FragmentPolygonOffset::end()
{
	GLState::disable((EnableModel)_offsetType);
}

