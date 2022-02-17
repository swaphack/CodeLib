#include "VertexArrayObject.h"

#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"
#include "VertexArrayAttrib.h"
#include "VertexAttribPointer.h"

using namespace render;

render::VertexArrayObject::VertexArrayObject()
{
	this->initVAO();
}

render::VertexArrayObject::~VertexArrayObject()
{
	this->relaseVAO();
	this->removeAllVertexAttribs();
}

uint32_t render::VertexArrayObject::getVAOID() const
{
	return _vaoID;
}

bool render::VertexArrayObject::isVertexArray()
{
	return  GLVertexArrays::isVertexArray(_vaoID);
}

void render::VertexArrayObject::bindVertexArray()
{
	GLVertexArrays::bindVertexArray(_vaoID);
}

void render::VertexArrayObject::unbindVertexArray()
{
	GLVertexArrays::bindVertexArray(0);
}

void render::VertexArrayObject::bindBuffer()
{
	if (getBuffer() == nullptr)
	{
		return;
	}

	GLBufferObjects::bindBuffer(BufferTarget::ARRAY_BUFFER, getBuffer()->getBufferID());

	//_bufferObject->bindBuffer();
}

void render::VertexArrayObject::bindBuffer(uint32_t bufferID)
{
	GLBufferObjects::bindBuffer(BufferTarget::ARRAY_BUFFER, bufferID);
}

void render::VertexArrayObject::unbindBuffer()
{
	GLBufferObjects::bindBuffer(BufferTarget::ARRAY_BUFFER, 0);
}

void render::VertexArrayObject::removeAllVertexAttribs()
{
	for (auto item : _mapVertexAttrib)
	{
		delete(item.second);
	}

	_mapVertexAttrib.clear();
}

void render::VertexArrayObject::enableVertexArrayAttrib(uint32_t index)
{
	auto attrib = getVertexAttrib<VertexArrayAttrib>(index);
	if (attrib != nullptr)
	{
		attrib->enableVertexArrayAttrib();
	}
}

void render::VertexArrayObject::disableVertexArrayAttrib(uint32_t index)
{
	auto attrib = getVertexAttrib<VertexArrayAttrib>(index);
	if (attrib != nullptr)
	{
		attrib->disableVertexArrayAttrib();
	}
}

void render::VertexArrayObject::setVertexAttribPointer(uint32_t index, uint32_t count, VertexAttribPointerType type, uint32_t stride, uint32_t offset)
{
	auto attrib = getVertexAttrib<VertexAttribPointer>(index);
	if (attrib != nullptr)
	{
		attrib->enableVertexArrayAttrib();
		attrib->setVertexAttribPointer(count, type, stride, offset);
	}
}

void render::VertexArrayObject::setVertexAttribDivisor(uint32_t index, uint32_t divisor)
{
	GLBufferObjects::setVertexAttribDivisor(index, divisor);
}

void render::VertexArrayObject::initVAO()
{
	_vaoID = GLVertexArrays::genVertexArray();
}

void render::VertexArrayObject::relaseVAO()
{
	GLVertexArrays::deleteVertexArray(_vaoID);
}
