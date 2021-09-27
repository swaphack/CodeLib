#include "XFBBufferObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"
#include "Common/Shader/ShaderProgram.h"

render::XFBBufferObject::XFBBufferObject()
{
	this->initTransformFeedback();
}

render::XFBBufferObject::~XFBBufferObject()
{
	this->releaseTransformFeedback();
	SAFE_RELEASE(_program);
}

uint32_t render::XFBBufferObject::getTransformFeedbackID() const
{
	return _transformFeedbackID;
}

bool render::XFBBufferObject::isValid() const
{
	return GLTransformFeedback::isTransformFeedback(_transformFeedbackID);
}

void render::XFBBufferObject::bindTransformFeedback()
{
	GLTransformFeedback::bindTransformFeedback(_transformFeedbackID);
}

void render::XFBBufferObject::unbindTransformFeedback()
{
	GLTransformFeedback::bindTransformFeedback(0);
}

void render::XFBBufferObject::setBufferBase(uint32_t index)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferBase(getTransformFeedbackID(), index, getBuffer()->getBufferID());
}

void render::XFBBufferObject::setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size)
{
	if (getBuffer() == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferRange(getTransformFeedbackID(), index, getBuffer()->getBufferID(), offset, size);
}

void render::XFBBufferObject::initTransformFeedback()
{
	_transformFeedbackID = GLTransformFeedback::createTransformFeedback();
}

void render::XFBBufferObject::releaseTransformFeedback()
{
	GLTransformFeedback::deleteTransformFeedback(_transformFeedbackID);

	_transformFeedbackID = 0;
}
