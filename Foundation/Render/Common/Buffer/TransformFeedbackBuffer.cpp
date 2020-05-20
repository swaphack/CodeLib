#include "TransformFeedbackBuffer.h"

render::TransformFeedbackBuffer::TransformFeedbackBuffer()
{
	this->setBufferTarget(BufferTarget::TRANSFORM_FEEDBACK_BUFFER);
}

render::TransformFeedbackBuffer::~TransformFeedbackBuffer()
{

}

void render::TransformFeedbackBuffer::setBufferSize(int size)
{
	this->setBufferData(size, BufferDataUsage::DYNAMIC_COPY);
}

