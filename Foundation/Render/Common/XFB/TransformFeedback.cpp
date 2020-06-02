#include "TransformFeedback.h"
#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"
#include "Common/Shader/ShaderProgram.h"

render::TransformFeedback::TransformFeedback()
{
	this->initTransformFeedback();
}

render::TransformFeedback::~TransformFeedback()
{
	this->releaseTransformFeedback();
	SAFE_RELEASE(_program);
}

uint32_t render::TransformFeedback::getTransformFeedbackID() const
{
	return _transformFeedbackID;
}

bool render::TransformFeedback::isValid() const
{
	return GLTransformFeedback::isTransformFeedback(_transformFeedbackID);
}

void render::TransformFeedback::bindTransformFeedback()
{
	GLTransformFeedback::bindTransformFeedback(_transformFeedbackID);
}

void render::TransformFeedback::unbindTransformFeedback()
{
	GLTransformFeedback::bindTransformFeedback(0);
}

void render::TransformFeedback::setBufferBase(uint32_t index)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferBase(getTransformFeedbackID(), index, getBuffer()->getBufferID());
}

void render::TransformFeedback::setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferRange(getTransformFeedbackID(), index, getBuffer()->getBufferID(), offset, size);
}

void render::TransformFeedback::setShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_program);
	SAFE_RETAIN(program);
	
	_program = program;
}

render::ShaderProgram* render::TransformFeedback::getShaderProgram() const
{
	return _program;
}

void render::TransformFeedback::setFeedbackVaryings(int count, const char* const* varyings, TransformFeedbackBufferMode mode)
{
	if (_program == nullptr)
	{
		return;
	}

	GLTransformFeedback::setTransformFeedbackVaryings(_program->getProgramID(), count, varyings, mode);
}

void render::TransformFeedback::beginWatch(TransformFeedbackPrimitiveMode mode)
{
	GLTransformFeedback::beginTransformFeedback(mode);
}

void render::TransformFeedback::pauseWatch()
{
	GLTransformFeedback::pauseTransformFeedback();
}

void render::TransformFeedback::resumeWatch()
{
	GLTransformFeedback::endTransformFeedback();
}

void render::TransformFeedback::endWatch()
{
	GLTransformFeedback::endTransformFeedback();
}

void render::TransformFeedback::initTransformFeedback()
{
	_transformFeedbackID = GLTransformFeedback::createTransformFeedback();
}

void render::TransformFeedback::releaseTransformFeedback()
{
	GLTransformFeedback::deleteTransformFeedback(_transformFeedbackID);

	_transformFeedbackID = 0;
}
