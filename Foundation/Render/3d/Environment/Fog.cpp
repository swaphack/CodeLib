#include "Fog.h"

using namespace render;

Fog::Fog()
:_near(0.0f)
, _far(1.0f)
, _fogMode(EFM_LINEAR)
, _fogEffect(EFE_NICEST)
, _density(1.0f)
{

}

Fog::~Fog()
{

}

void Fog::draw()
{
	ColorNode::draw();

	sys::Color4B c = getColor();
	float color[4] = { c.red / COLOR_FLOAT_VALUE, c.green / COLOR_FLOAT_VALUE, c.blue / COLOR_FLOAT_VALUE, c.alpha / COLOR_FLOAT_VALUE };
	float nearValue = _near / Tool::getGLViewSize().getDeep();
	float farValue = _far / Tool::getGLViewSize().getDeep();

	glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, _fogMode);	
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_DENSITY, _density);
	glHint(GL_FOG_HINT, _fogEffect);
	glFogf(GL_FOG_START, nearValue);
	glFogf(GL_FOG_END, farValue);
}
