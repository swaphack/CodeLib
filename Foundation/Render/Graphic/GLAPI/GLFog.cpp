#include "GLFog.h"

using namespace render;

void GLFog::setFogMode(FogMode mode)
{
	glFogi((GLenum)FogParameter::FOG_MODE, (GLint)mode);
}

void GLFog::setFogDensity(float value)
{
	glFogf((GLenum)FogParameter::FOG_DENSITY, value);
}

void GLFog::setFogStart(float value)
{
	glFogf((GLenum)FogParameter::FOG_START, value);
}

void GLFog::setFogEnd(float value)
{
	
	glFogf((GLenum)FogParameter::FOG_END, value);
}

void GLFog::setFogIndex(float value)
{
	glFogf((GLenum)FogParameter::FOG_INDEX, value);
}

void GLFog::setFogColor(const phy::Color4F& color)
{
	float c[4] = { color[0], color[1], color[2], color[3] };
	glFogfv((GLenum)FogParameter::FOG_COLOR, c);
}