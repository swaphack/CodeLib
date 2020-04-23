#include "GLFixedFunction.h"

using namespace render;


void GLFixedFunction::setAccum(AccumOp op, float value)
{
	glAccum((GLenum)op, value);
}

void GLFixedFunction::setAlphaFunc(AlphaFunction func, float value)
{
	glAlphaFunc((GLenum)func, value);
}

void GLFixedFunction::clearAccum(float red, float green, float blue, float alpha)
{
	glClearAccum(red, green, blue, alpha);
}

void GLFixedFunction::getTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, float* value)
{
	glGetTexEnvfv((GLenum)target, (GLenum)parameter, value);
}

void GLFixedFunction::getTexGen(TextureCoordName coord, TextureGenParameter parameter, float* value)
{
	glGetTexGenfv((GLenum)coord, (GLenum)parameter, value);
}

void GLFixedFunction::setIndexMask(uint32_t mask)
{
	glIndexMask(mask);
}

void GLFixedFunction::pushAttrib(AttribMask value)
{
	glPushAttrib((GLbitfield)value);
}

void GLFixedFunction::popAttrib()
{
	glPopAttrib();
}

void GLFixedFunction::setShadeModel(ShadingModel model)
{
	glShadeModel((GLenum)model);
}