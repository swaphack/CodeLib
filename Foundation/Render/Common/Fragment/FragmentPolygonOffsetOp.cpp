#include "FragmentPolygonOffsetOp.h"
#include "Graphic/import.h"

render::FragmentPolygonOffsetOp::FragmentPolygonOffsetOp()
{
	_offsetType = PolygonOffsetType::POLYGON_OFFSET_FILL;
	_offset.t1 = 0;
	_offset.t2 = 1;
}

render::FragmentPolygonOffsetOp::~FragmentPolygonOffsetOp()
{

}

void render::FragmentPolygonOffsetOp::setOffsetType(PolygonOffsetType type)
{
	_offsetType = type;
}

void render::FragmentPolygonOffsetOp::setOffset(float factor, float units)
{
	_offset.t1 = factor;
	_offset.t2 = units;
}

void render::FragmentPolygonOffsetOp::begin()
{
	GLState::enable((EnableModel)_offsetType);
}

void render::FragmentPolygonOffsetOp::update()
{
	GLState::setPolygonOffset(_offset.t1, _offset.t2);
}

void render::FragmentPolygonOffsetOp::end()
{
	GLState::disable((EnableModel)_offsetType);
}

