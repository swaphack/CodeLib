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
	Node::draw();
}

void DrawNode::setColor( sys::Color4B color )
{
	_color = color;
}

sys::Color4B& DrawNode::getColor()
{
	return _color;
}

void DrawNode::setWidth( float width )
{
	_width = width;
}

float DrawNode::getWidth()
{
	return _width;
}

void DrawNode::updateTranform()
{
	Node::updateTranform();
}

void DrawNode::initSelf()
{
	Node::initSelf();
}
