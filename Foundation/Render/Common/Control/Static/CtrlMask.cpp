#include "CtrlMask.h"

using namespace render;

CtrlMask::CtrlMask()
:_opacity(255)
{
	_blend.src = GL_DST_COLOR;
	_blend.dest = GL_ZERO;
}

CtrlMask::~CtrlMask()
{

}

void CtrlMask::draw()
{
	ColorNode::draw();

	GLTool::beginBlend(_blend);

	sys::Color4B color = getColor();
	color.red *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;
	color.green *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;
	color.blue *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;
	color.alpha *= (255 - _opacity) / sys::COLOR_FLOAT_VALUE;

	GLTool::setColor(color);

	GLTool::drawRect(&_rectVertex, GL_QUADS);

	GLTool::endBlend();
}

void CtrlMask::setOpacity(uchar opacity)
{
	_opacity = opacity;
}

uchar CtrlMask::getOpacity()
{
	return _opacity;
}
