#include "TransformFeedbackObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"
#include "Common/Shader/ShaderProgram.h"

render::TransformFeedbackObject::TransformFeedbackObject()
{
	this->initTransformFeedback();
}

render::TransformFeedbackObject::~TransformFeedbackObject()
{
	this->releaseTransformFeedback();
	SAFE_RELEASE(_program);
}

uint32_t render::TransformFeedbackObject::getTransformFeedbackID() const
{
	return _transformFeedbackID;
}

bool render::TransformFeedbackObject::isValid() const
{
	return GLTransformFeedback::isTransformFeedback(_transformFeedbackID);
}

void render::TransformFeedbackObject::bindTransformFeedback()
{
	GLTransformFeedback::bindTransformFeedback(_transformFeedbackID);
}

void render::TransformFeedbackObject::setBufferBase(uint32_t index)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferBase(getTransformFeedbackID(), index, getBuffer()->getBufferID());
}

void render::TransformFeedbackObject::setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferRange(getTransformFeedbackID(), index, getBuffer()->getBufferID(), offset, size);
}

void render::TransformFeedbackObject::setShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_program);
	SAFE_RETAIN(program);
	
	_program = program;
}

render::ShaderProgram* render::TransformFeedbackObject::getShaderProgram() const
{
	return _program;
}

void render::TransformFeedbackObject::setFeedbackVaryings(int count, const char** varyings, TransformFeedbackBufferMode mode)
{
	if (_program == nullptr)
	{
		return;
	}

	GLTransformFeedback::setTransformFeedbackVaryings(_program->getProgramID(), count, varyings, mode);
}

void render::TransformFeedbackObject::beginWatch(TransformFeedbackPrimitiveMode mode)
{
	GLTransformFeedback::beginTransformFeedback(mode);
}

void render::TransformFeedbackObject::pauseWatch()
{
	GLTransformFeedback::pauseTransformFeedback();
}

void render::TransformFeedbackObject::resumeWatch()
{
	GLTransformFeedback::endTransformFeedback();
}

void render::TransformFeedbackObject::endWatch()
{
	GLTransformFeedback::endTransformFeedback();
}

void render::TransformFeedbackObject::initTransformFeedback()
{
	_transformFeedbackID = GLTransformFeedback::createTransformFeedback();
}

void render::TransformFeedbackObject::releaseTransformFeedback()
{
	GLTransformFeedback::deleteTransformFeedback(_transformFeedbackID);

	_transformFeedbackID = 0;
}
