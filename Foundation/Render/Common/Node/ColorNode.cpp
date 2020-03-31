#include "ColorNode.h"
#include "Graphic/import.h"
using namespace render;


ColorNode::ColorNode()
{

}

ColorNode::~ColorNode()
{

}

void ColorNode::draw()
{
	GLState::enable(EnableModel::BLEND);
	GLFragment::setBlend(getBlend().src, getBlend().dest);
	GLVertex::setColor(getColor());

	this->drawSample();

	GLState::disable(EnableModel::BLEND);
}

void ColorNode::drawSample()
{

}
