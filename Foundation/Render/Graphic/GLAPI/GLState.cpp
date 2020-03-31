#include "GLState.h"
#include "macros.h"

using namespace render;

void GLState::enable(EnableModel capability)
{
	glEnable((GLenum)capability);
}

void GLState::disable(EnableModel capability)
{
	glDisable((GLenum)capability);
}

bool GLState::isEnabled(EnableModel capability)
{
	return glIsEnabled((GLenum)capability) != 0;
}

void GLState::getBoolean(GetTarget pname, uint8_t* value)
{
	return glGetBooleanv((GLenum)pname, value);
}

void GLState::getDouble(GetTarget pname, double* value)
{
	return glGetDoublev((GLenum)pname, value);
}

void GLState::getFloat(GetTarget pname, float* value)
{
	return glGetFloatv((GLenum)pname, value);
}

void GLState::getInt(GetTarget pname, int* value)
{
	return glGetIntegerv((GLenum)pname, value);
}

void GLState::finish()
{
	glFinish();
}

void GLState::flush()
{
	glFlush();
}

void GLState::pushAttrib(AttribMask value)
{
	glPushAttrib((GLbitfield)value);
}

void GLState::popAttrib()
{
	glPopAttrib();
}

void GLState::pushClientAttrib(ClientAttribMask value)
{
	glPushClientAttrib((GLbitfield)value);
}

void GLState::popClientAttrib()
{
	glPopClientAttrib();
}

void GLState::getClipPlane(ClipPlaneName name, double* equation)
{
	glGetClipPlane((GLenum)name, equation);
}

void GLState::getPixelMap(PixelMap map, float* value)
{
	glGetPixelMapfv((GLenum)map, value);
}

void GLState::getTexImage(TextureTarget target, int level, TextureParameter internalFormat, PixelType pixelType, void* data)
{
	glGetTexImage((GLenum)target, level, (GLenum)internalFormat, (GLenum)pixelType, data);
}

void GLState::getLight(LightName name, LightParameter mode, float* value)
{
	glGetLightfv((GLenum)name, (GLenum)mode, value);
}

void GLState::getPolygonStipple(uint8_t* mask)
{
	glGetPolygonStipple(mask);
}

void GLState::getTexLevelParameter(TextureTarget target, int level, GetTextureParameter parameter, float* value)
{
	glGetTexLevelParameterfv((GLenum)target, level, (GLenum)parameter, value);
}

void GLState::getMap(MapTarget target, GetMapTarget parameter, float* value)
{
	glGetMapfv((GLenum)target, (GLenum)parameter, value);
}

void GLState::getTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, float* value)
{
	glGetTexEnvfv((GLenum)target, (GLenum)parameter, value);
}

void GLState::getTexParameter(TextureTarget target, GetTextureParameter parameter, int* value)
{
	glGetTexParameteriv((GLenum)target, (GLenum)parameter, value);
}

void GLState::getTexParameter(TextureTarget target, GetTextureParameter parameter, float* value)
{
	glGetTexParameterfv((GLenum)target, (GLenum)parameter, value);
}

void GLState::getMaterial(GetMaterialFace face, MaterialParameter parameter, float* value)
{
	glGetMaterialfv((GLenum)face, (GLenum)parameter, value);
}

void GLState::getTexGen(TextureCoordName coord, TextureGenParameter parameter, float* value)
{
	glGetTexGenfv((GLenum)coord, (GLenum)parameter, value);
}

void GLState::enableClientState(ClientArrayType type)
{
	glEnableClientState((GLenum)type);
}

void GLState::disableClientState(ClientArrayType type)
{
	glDisableClientState((GLenum)type);
}

void GLState::getPointer(GetPointerTarget target, void** value)
{
	glGetPointerv((GLenum)target, value);
}
