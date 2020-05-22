#include "VertexArrayObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/Buffer.h"
#include "VertexArrayAttrib.h"

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
