#include "LineNode.h"

using namespace render;

LineNode::LineNode()
{

}

LineNode::~LineNode()
{

}

void LineNode::draw()
{
	DrawNode::draw();

	sys::Color4B color = this->getColor();
	GLTool::setColor(color.red, color.green, color.blue, color.alpha);
	glLineWidth(this->getWidth());
	glBegin(GL_LINES);
	glVertex3f(_obLine[0].x, _obLine[0].y, _obLine[0].z);
	glVertex3f(_obLine[1].x, _obLine[1].y, _obLine[1].z);
	glEnd();
}

void LineNode::setDestination( float x, float y, float z /*= 0*/ )
{
	_destPosition.x = x;
	_destPosition.y = y;
	_destPosition.z = z;
	setDirty(true);
}

const sys::Vector& LineNode::getDestination()
{
	return _destPosition;
}

void LineNode::setSource(float x, float y, float z /*= 0*/)
{
	_srcPosition.x = x;
	_srcPosition.y = y;
	_srcPosition.z = z;
	setDirty(true);
}

const sys::Vector& LineNode::getSource()
{
	return _srcPosition;
}

void LineNode::initSelf()
{
	DrawNode::initSelf();

	_obLine[0] = _srcPosition;
	_obLine[0].add(_position);

	_obLine[1] = _destPosition;
	_obLine[1].add(_position);

	Tool::convertToOGLPoisition(_obLine[0], _obLine[0]);
	Tool::convertToOGLPoisition(_obLine[1], _obLine[1]);
}
