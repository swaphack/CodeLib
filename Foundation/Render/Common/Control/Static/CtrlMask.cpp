#include "CtrlMask.h"

using namespace render;

CtrlMask::CtrlMask()
:_opacity(255)
{

}

CtrlMask::~CtrlMask()
{

}

void CtrlMask::draw()
{
	Node::draw();

	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR, GL_ZERO);

	sys::Color4B color = getColor();
	color.red *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;
	color.green *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;
	color.blue *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;
	color.alpha *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;

	GLTool::setColor(color);

	GLTool::drawRect(&_rectVertex, GL_QUADS);

	glDisable(GL_BLEND);
}

void CtrlMask::setOpacity(uchar opacity)
{
	_opacity = opacity;
}

uchar CtrlMask::getOpacity()
{
	return _opacity;
}
