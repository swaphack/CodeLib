#include "DrawNode.h"

using namespace render;


DrawNode::DrawNode()
:_width(1.0)
, _drawMode(EBM_POINTS)
{
}

DrawNode::~DrawNode()
{
}

void DrawNode::draw()
{
	ColorNode::draw();	

	G_DRAWCOMMANDER->addCommand(DCDraw::create(_drawMode, _points, _width, _color, _opacity, _blend));
}

void DrawNode::setWidth( float width )
{
	_width = width;
}

float DrawNode::getWidth()
{
	return _width;
}

void DrawNode::setDrawMode(int mode)
{
	_drawMode = mode;
}

int DrawNode::getDrawMode()
{
	return _drawMode;
}

void DrawNode::initSelf()
{
	Node::initSelf();
}

void DrawNode::appendPoint(const sys::Vector3& point)
{
	sys::Vector3 pos;
	Tool::convertToOGLPoisition(point, pos);
	_points.push_back(pos);
}

void DrawNode::removeAllPoints()
{
	_points.clear();
}
