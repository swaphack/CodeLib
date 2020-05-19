#include "VertexArrayObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/BufferObject.h"
#include "VAOAttrib.h"

using namespace render;

render::VertexArrayObject::VertexArrayObject()
{
	this->initVAO();
}

render::VertexArrayObject::~VertexArrayObject()
{
	this->relaseVAO();
	this->removeAllVertexAttribs();
	SAFE_RELEASE(_bufferObject);
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

void render::VertexArrayObject::setBufferObject(BufferObject* buffer)
{
	SAFE_RELEASE(_bufferObject);
	SAFE_RETAIN(buffer);
	_bufferObject = buffer;
}

render::BufferObject* render::VertexArrayObject::getBufferObject()
{
	return _bufferObject;
}

void render::VertexArrayObject::bindBuffer()
{
	if (_bufferObject == nullptr || !_bufferObject->isBuffer())
	{
		return;
	}

	_bufferObject->bindBuffer();
}

void render::VertexArrayObject::removeAllVertexAttribs()
{
	for (auto item : _mapVertexAttrib)
	{
		delete(item.second);
	}

	_mapVertexAttrib.clear();
}

void render::VertexArrayObject::initVAO()
{
	_vaoID = GLVertexArrays::genVertexArray();
}

void render::VertexArrayObject::relaseVAO()
{
	GLVertexArrays::deleteVertexArray(_vaoID);
}
