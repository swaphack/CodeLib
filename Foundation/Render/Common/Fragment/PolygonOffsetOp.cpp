#include "PolygonOffsetOp.h"
#include "Graphic/import.h"

render::PolygonOffsetOp::PolygonOffsetOp()
{
	_offsetType = PolygonOffsetType::POLYGON_OFFSET_FILL;
	_offset.t1 = 0;
	_offset.t2 = 1;
}

render::PolygonOffsetOp::~PolygonOffsetOp()
{

}

void render::PolygonOffsetOp::setOffsetType(PolygonOffsetType type)
{
	_offsetType = type;
}

void render::PolygonOffsetOp::setOffset(float factor, float units)
{
	_offset.t1 = factor;
	_offset.t2 = units;
}

void render::PolygonOffsetOp::startTest()
{
	GLState::enable((EnableModel)_offsetType);
}

void render::PolygonOffsetOp::test()
{
	GLState::setPolygonOffset(_offset.t1, _offset.t2);
}

void render::PolygonOffsetOp::endTest()
{
	GLState::disable((EnableModel)_offsetType);
}

