#include "VertexArrayBufferObject.h"
#include "VertexArrayObject.h"
#include "VertexAttribPointer.h"
#include "Common/Buffer/ArrayBuffer.h"
#include "Graphic/import.h"

render::VertexArrayBufferObject::VertexArrayBufferObject()
{
	this->initVABO();
}

render::VertexArrayBufferObject::~VertexArrayBufferObject()
{
	this->releaseVABO();
}

void render::VertexArrayBufferObject::resizeBuffer(uint32_t size, BufferDataUsage usage)
{
	_buffer->bindBuffer();
	_buffer->setBufferData(size, nullptr, usage);
	GLDebug::showError();
}

void render::VertexArrayBufferObject::setSubBuffer(uint32_t offset, uint32_t size, const void* value)
{
	_buffer->bindBuffer();
	_buffer->setBufferSubData(offset, size, value);
	GLDebug::showError();
}

void render::VertexArrayBufferObject::setVertexAttribPointer(int index, uint32_t count, VertexAttribPointerType type, uint32_t stride, uint32_t offset)
{
	GLDebug::showError();
	auto pData = _vao->getVertexAttrib<VertexAttribPointer>(index);
	pData->enableVertexArrayAttrib();
	pData->setVertexAttribPointer(count, type, stride, offset);
	GLDebug::showError();
}

void render::VertexArrayBufferObject::bindVertexArray()
{
	_vao->bindVertexArray();
	GLDebug::showError();
}

void render::VertexArrayBufferObject::bindBuffer()
{
	_buffer->bindBuffer();
	GLDebug::showError();
}

void render::VertexArrayBufferObject::unbindBuffer()
{
	_buffer->unbindBuffer();
}

void render::VertexArrayBufferObject::unbindVertexArray()
{
	_vao->unbindVertexArray();
	GLDebug::showError();
}

void render::VertexArrayBufferObject::enableVertexArrayAttrib(uint32_t index)
{
	_vao->enableVertexArrayAttrib(index);
}

void render::VertexArrayBufferObject::disableVertexArrayAttrib(uint32_t index)
{
	_vao->disableVertexArrayAttrib(index);
}

void render::VertexArrayBufferObject::initVABO()
{
	_vao = CREATE_OBJECT(VertexArrayObject);
	SAFE_RETAIN(_vao);
	_buffer = CREATE_OBJECT(ArrayBuffer);
	SAFE_RETAIN(_buffer);

	_vao->setBuffer(_buffer);
	//_vao->bindVertexArray();
	//_vao->bindBuffer();
	//_vao->unbindVertexArray();
}

void render::VertexArrayBufferObject::releaseVABO()
{
	SAFE_RELEASE(_vao);
	SAFE_RELEASE(_buffer);
}

uint32_t render::VertexArrayBufferObject::getTypeSize(VertexAttribPointerType type)
{
	switch (type)
	{
	case VertexAttribPointerType::BYTE:
		return sizeof(int8_t);
		break;
	case VertexAttribPointerType::UNSIGNED_BYTE:
		return sizeof(uint8_t);
		break;
	case VertexAttribPointerType::SHORT:
		return sizeof(int16_t);
		break;
	case VertexAttribPointerType::UNSIGNED_SHORT:
		return sizeof(uint16_t);
		break;
	case VertexAttribPointerType::INT:
		return sizeof(int32_t);
		break;
	case VertexAttribPointerType::UNSIGNED_INT:
		return sizeof(uint32_t);
		break;
	case VertexAttribPointerType::HALF_FLOAT:
		return sizeof(float) / 2;
		break;
	case VertexAttribPointerType::FLOAT:
		return sizeof(float);
		break;
	case VertexAttribPointerType::DOUBLE:
		return sizeof(double);
		break;
	case VertexAttribPointerType::FIXED:
		return sizeof(int32_t) / 2;
		break;
	case VertexAttribPointerType::INT_2_10_10_10_REV:
		return sizeof(int32_t);
		break;
	case VertexAttribPointerType::UNSIGNED_INT_2_10_10_10_REV:
		return sizeof(uint32_t);
		break;
	case VertexAttribPointerType::UNSIGNED_INT_10F_11F_11F_REV:
		return sizeof(uint32_t);
		break;
	default:
		break;
	}

	return 0;
}
