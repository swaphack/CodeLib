#include "CtrlFog.h"

using namespace render;

CtrlFog::CtrlFog()
:_near(0.0f)
, _far(1.0f)
, _fogMode(EFM_LINEAR)
, _fogEffect(EFE_NICEST)
, _density(1.0f)
{

}

CtrlFog::~CtrlFog()
{

}

void CtrlFog::draw()
{
	Node::draw();

	sys::Color4B c = getColor();
	float color[4] = { c.red / sys::COLOR_FLOAT_VALUE, c.green / sys::COLOR_FLOAT_VALUE, c.blue / sys::COLOR_FLOAT_VALUE, c.alpha / sys::COLOR_FLOAT_VALUE };
	float nearValue = _near / Tool::getGLViewSize().deep;
	float farValue = _far / Tool::getGLViewSize().deep;

	glFogi(GL_FOG_MODE, _fogMode);	
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_DENSITY, _density);
	glHint(GL_FOG_HINT, _fogEffect);
	glFogf(GL_FOG_START, nearValue);
	glFogf(GL_FOG_END, farValue);
	glEnable(GL_FOG);
}
