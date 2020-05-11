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
	//GLState::pushAttrib(AttribMask::COLOR_BUFFER_BIT);

	GLState::enable(EnableModel::BLEND);
	GLState::setBlendFunc(getBlend().src, getBlend().dest);
	GLVertex::setColor(getColor());

	this->drawSample();

	GLState::disable(EnableModel::BLEND);

	//GLState::popAttrib();
}

void ColorNode::drawSample()
{

}
