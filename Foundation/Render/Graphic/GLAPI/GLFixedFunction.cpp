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
	glPushAttrib((uint32_t)value);
}

void GLFixedFunction::popAttrib()
{
	glPopAttrib();
}

void GLFixedFunction::setShadeModel(ShadingModel model)
{
	glShadeModel((GLenum)model);
}

void render::GLFixedFunction::setTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, float value)
{
	glTexEnvf((GLenum)target, (GLenum)parameter, value);
}

void render::GLFixedFunction::setTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, int value)
{
	glTexEnvi((GLenum)target, (GLenum)parameter, value);
}

void render::GLFixedFunction::setTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, TextureEnvValue value)
{
	glTexEnvi((GLenum)target, (GLenum)parameter, (int)value);
}

void render::GLFixedFunction::setTexEnv(TextureEnvTargetv target, TextureEnvParameterv parameter, const int* value)
{
	glTexEnviv((GLenum)target, (GLenum)parameter, value);
}

void render::GLFixedFunction::setTexEnv(TextureEnvTargetv target, TextureEnvParameterv parameter, const float* value)
{
	glTexEnvfv((GLenum)target, (GLenum)parameter, value);
}


