#include "GLTransformFeedback.h"

using namespace render;

void GLTransformFeedback::beginTransformFeedback(TransformFeedbackPrimitiveMode mode)
{
	glBeginTransformFeedback((GLenum)mode);
}

void GLTransformFeedback::bindTransformFeedback(uint32_t id)
{
	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, id);
}

void GLTransformFeedback::createTransformFeedbacks(int n, uint32_t* ids)
{
	glCreateTransformFeedbacks(n, ids);
}

void GLTransformFeedback::deleteTransformFeedbacks(int n, const uint32_t* ids)
{
	glDeleteTransformFeedbacks(n, ids);
}

void GLTransformFeedback::drawTransformFeedback(DrawTransformFeedbackMode mode, uint32_t id)
{
	glDrawTransformFeedback((GLenum)mode, id);
}

void GLTransformFeedback::drawTransformFeedbackInstanced(DrawTransformFeedbackMode mode, uint32_t id, int primcount)
{
	glDrawTransformFeedbackInstanced((GLenum)mode, id, primcount);
}

void GLTransformFeedback::drawTransformFeedbackStream(DrawTransformFeedbackMode mode, uint32_t id, uint32_t stream)
{
	glDrawTransformFeedbackStream((GLenum)mode, id, stream);
}

void GLTransformFeedback::drawTransformFeedbackStreamInstanced(DrawTransformFeedbackMode mode, uint32_t id, uint32_t stream, int primcount)
{
	glDrawTransformFeedbackStreamInstanced((GLenum)mode, id, stream, primcount);
}

void GLTransformFeedback::endTransformFeedback()
{
	glEndTransformFeedback();
}

void GLTransformFeedback::genTransformFeedbacks(int n, uint32_t* ids)
{
	glGenTransformFeedbacks(n, ids);
}

void GLTransformFeedback::getTransformFeedback(uint32_t xfb, GetTransformFeedbackParameter pname, uint32_t index, int *param)
{
	glGetTransformFeedbacki_v(xfb, (GLenum)pname, index, param);
}

void GLTransformFeedback::getTransformFeedbackVarying(uint32_t program, uint32_t index, int bufSize, int *length, int *size, uint32_t *type, char *name)
{
	glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}

bool GLTransformFeedback::isTransformFeedback(uint32_t id)
{
	return glIsTransformFeedback(id) == GL_TRUE;
}

void GLTransformFeedback::pauseTransformFeedback()
{
	glPauseTransformFeedback();
}

void GLTransformFeedback::resumeTransformFeedback()
{
	glResumeTransformFeedback();
}

void GLTransformFeedback::setTransformFeedbackBufferBase(uint32_t xfb, uint32_t index, uint32_t buffer)
{
	glTransformFeedbackBufferBase(xfb, index, buffer);
}

void GLTransformFeedback::setTransformFeedbackBufferRange(uint32_t xfb, uint32_t index, uint32_t buffer, GLintptr offset, int size)
{
	glTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
}

void GLTransformFeedback::setTransformFeedbackVaryings(uint32_t program, int count, const char** varyings, TransformFeedbackBufferMode mode)
{
	glTransformFeedbackVaryings(program, count, varyings, (GLenum)mode);
}

