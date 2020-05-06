#include "VertexArrayObject.h"
#include "Graphic/import.h"
#include "BufferObject.h"
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
	SAFE_RELEASE(_bufferObj);
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
	SAFE_RELEASE(_bufferObj);
	SAFE_RETAIN(buffer);
	_bufferObj = buffer;
}

render::BufferObject* render::VertexArrayObject::getBufferObject()
{
	return _bufferObj;
}

void render::VertexArrayObject::bindBuffer()
{
	if (_bufferObj == nullptr || !_bufferObj->isBuffer())
	{
		return;
	}

	_bufferObj->bindBuffer();
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
