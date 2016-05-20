#include "DrawNode.h"

using namespace render;


DrawNode::DrawNode()
:_width(1.0)
{
}

DrawNode::~DrawNode()
{
}

void DrawNode::draw()
{
	ColorNode::draw();
}

void DrawNode::setWidth( float width )
{
	_width = width;
}

float DrawNode::getWidth()
{
	return _width;
}

void DrawNode::initSelf()
{
	Node::initSelf();
}
