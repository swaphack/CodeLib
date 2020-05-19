#include "TransformFeedbackObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/import.h"
render::TransformFeedbackObject::TransformFeedbackObject()
{
	this->initTransformFeedback();
}

render::TransformFeedbackObject::~TransformFeedbackObject()
{
	this->releaseTransformFeedback();

	SAFE_RELEASE(_bufferObject);
}

uint32_t render::TransformFeedbackObject::getTransformFeedbackID() const
{
	return _transformFeedbackID;
}

bool render::TransformFeedbackObject::isValid()
{
	return GLTransformFeedback::isTransformFeedback(_transformFeedbackID);
}

void render::TransformFeedbackObject::setBufferObject(BufferObject* obj)
{
	SAFE_RELEASE(_bufferObject);
	SAFE_RETAIN(obj);
	_bufferObject = obj;
}

void render::TransformFeedbackObject::bindTransformFeedback()
{
	GLTransformFeedback::bindTransformFeedback(_transformFeedbackID);
}

void render::TransformFeedbackObject::setBufferBase(uint32_t index)
{
	if (_bufferObject == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferBase(getTransformFeedbackID(), index, _bufferObject->getBufferID());
}

void render::TransformFeedbackObject::setBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size)
{
	if (_bufferObject == nullptr)
	{
		return;
	}
	GLTransformFeedback::setTransformFeedbackBufferRange(getTransformFeedbackID(), index, _bufferObject->getBufferID(), offset, size);
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
