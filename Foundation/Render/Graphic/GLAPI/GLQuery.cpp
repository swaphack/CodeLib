#include "GLQuery.h"

using namespace render;

void GLQuery::beginConditionalRender(uint32_t id, QueryMode mode)
{
	glBeginConditionalRender(id, (GLenum)mode);
}

void GLQuery::endConditionalRender()
{
	glEndConditionalRender();
}

void GLQuery::beginQuery(QueryTarget target, uint32_t id)
{
	glBeginQuery((GLenum)target, id);
}

void GLQuery::endQuery(QueryTarget target)
{
	glEndQuery((GLenum)target);
}

void GLQuery::genQueries(int n, uint32_t* ids)
{
	glGenQueries(n, ids);
}

void GLQuery::deleteQueries(int n, const uint32_t* ids)
{
	glDeleteQueries(n, ids);
}

void GLQuery::getQueryObject(uint32_t id, QueryParameter name, uint32_t* params)
{
	glGetQueryObjectuiv(id, (GLenum)name, params);
}

void GLQuery::getQuery(QueryTarget target, QueryParameter name, int32_t* params)
{
	glGetQueryiv((GLenum)target, (GLenum)name, params);
}

bool GLQuery::isQuery(uint32_t id)
{
	return glIsQuery(id) == GL_TRUE;
}

