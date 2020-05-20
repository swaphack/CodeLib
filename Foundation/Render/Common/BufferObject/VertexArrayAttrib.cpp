#include "VertexArrayAttrib.h"
#include "Graphic/import.h"
#include "VertexArrayObject.h"

using namespace render;

render::VertexArrayAttrib::VertexArrayAttrib(uint32_t index, VertexArrayObject* obj)
{
	_index = index;
	_vaobj = obj;
}

render::VertexArrayAttrib::~VertexArrayAttrib()
{

}

render::VertexArrayObject* render::VertexArrayAttrib::getVAO()
{
	return _vaobj;
}

uint32_t render::VertexArrayAttrib::getIndex() const
{
	return _index;
}

void render::VertexArrayAttrib::enableVertexArrayAttrib()
{
	if (_vaobj == nullptr)
	{
		return;
	}
	GLBufferObjects::enableVertexArrayAttrib(_vaobj->getVAOID(), _index);
}

void render::VertexArrayAttrib::disableVertexArrayAttrib()
{
	GLBufferObjects::disableVertexArrayAttrib(_vaobj->getVAOID(), _index);
}
void render::VertexArrayAttrib::enableVertexAttribArray()
{
	GLBufferObjects::enableVertexAttribArray(_index);
}

void render::VertexArrayAttrib::disableVertexAttribArray()
{
	GLBufferObjects::disableVertexAttribArray(_index);
}

