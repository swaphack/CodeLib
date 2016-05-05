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
// 	if (!this->isRelativeWithParent())
// 	{
// 		glLoadIdentity();
// 	}
// 
// 	glTranslatef(_obPosition.x, _obPosition.y, _obPosition.z);
// 	glRotatef(_rotation.x, 1, 0, 0);
// 	glRotatef(_rotation.y, 0, 1, 0);
// 	glRotatef(_rotation.z, 0, 0, 1);
// 	glScalef(_scale.x, _scale.y, _scale.z);
}

void DrawNode::initSelf()
{
	Node::initSelf();
}

// void DrawNode::updateSelf()
// {
// 	this->initTranform();
// 	_psr.initDrawNode();
// }
