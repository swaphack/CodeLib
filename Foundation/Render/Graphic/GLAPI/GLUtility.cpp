#include "GLUtility.h"

using namespace render;

const uint8_t* GLUtility::getString(StringName name)
{
	return glGetString((GLenum)name);
}

void render::GLUtility::dispatchCompute(uint32_t numX, uint32_t numY, uint32_t numZ)
{
	glDispatchCompute(numX, numY, numZ);
}

void render::GLUtility::dispatchComputeIndirect(ptrdiff_t indirect)
{
	glDispatchComputeIndirect(indirect);
}

GraphicsResetStatus render::GLUtility::getGraphicsResetStatus()
{
	return (GraphicsResetStatus)glGetGraphicsResetStatus();
}

void render::GLUtility::getInternalFormat(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params)
{
	glGetInternalformativ((GLenum)target, (GLenum)internalformat, (GLenum)pname, bufSize, params);
}

void render::GLUtility::getInternalFormat(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params)
{
	glGetInternalformati64v((GLenum)target, (GLenum)internalformat, (GLenum)pname, bufSize, params);
}

void render::GLUtility::getMultiSample(GLuint index, GLfloat* val)
{
	glGetMultisamplefv(GL_SAMPLE_POSITION, index, val);
}

void render::GLUtility::setMemoryBarrier(uint32_t barriers)
{
	glMemoryBarrier(barriers);
}

void render::GLUtility::setMemoryBarrierByRegion(uint32_t barriers)
{
	glMemoryBarrierByRegion(barriers);
}

