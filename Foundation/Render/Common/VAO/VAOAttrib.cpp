#include "VAOAttrib.h"
#include "Graphic/import.h"
#include "VertexArrayObject.h"

using namespace render;

render::VAOAttrib::VAOAttrib(uint32_t index, VertexArrayObject* obj)
{
	_index = index;
	_vaobj = obj;
}

render::VAOAttrib::~VAOAttrib()
{

}

render::VertexArrayObject* render::VAOAttrib::getVAO()
{
	return _vaobj;
}

uint32_t render::VAOAttrib::getIndex() const
{
	return _index;
}

void render::VAOAttrib::enableVertexArrayAttrib()
{
	if (_vaobj == nullptr)
	{
		return;
	}
	GLBufferObjects::enableVertexArrayAttrib(_vaobj->getVAOID(), _index);
}

void render::VAOAttrib::disableVertexArrayAttrib()
{
	GLBufferObjects::disableVertexArrayAttrib(_vaobj->getVAOID(), _index);
}
void render::VAOAttrib::enableVertexAttribArray()
{
	GLBufferObjects::enableVertexAttribArray(_index);
}

void render::VAOAttrib::disableVertexAttribArray()
{
	GLBufferObjects::disableVertexAttribArray(_index);
}

