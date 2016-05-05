#include "PointNode.h"

using namespace render;

PointNode::PointNode()
{

}

PointNode::~PointNode()
{

}

void PointNode::draw()
{
	DrawNode::draw();

	sys::Color4B color = this->getColor();

	GLTool::setColor(color.red, color.green, color.blue, color.alpha);
	glPointSize(this->getWidth());
	glBegin(GL_POINTS);
	glVertex3f(_obPosition.x, _obPosition.y, _obPosition.z);
	glEnd();
}


