#include "GLVertexArrays.h"

using namespace render;

void GLVertexArrays::genVertexArrays(int size, uint32_t* arys)
{
	glGenVertexArrays(size, arys);
}

void GLVertexArrays::bindVertexArray(uint32_t ary)
{
	glBindVertexArray(ary);
}

void GLVertexArrays::deleteVertexArrays(int size, const uint32_t* arys)
{
	glDeleteVertexArrays(size, arys);
}

bool GLVertexArrays::isVertexArray(uint32_t ary)
{
	return glIsVertexArray(ary) == GL_TRUE;
}

uint32_t GLVertexArrays::genVertexArray()
{
	uint32_t value = 0;
	genVertexArrays(1, &value);

	return value;
}

void GLVertexArrays::deleteVertexArray(uint32_t ary)
{
	deleteVertexArrays(1, &ary);
}

void render::GLVertexArrays::createVertexArrays(int size, uint32_t* arys)
{
	glCreateVertexArrays(size, arys);
}

uint32_t render::GLVertexArrays::createVertexArray()
{
	uint32_t value = 0;
	createVertexArrays(1, &value);

	return value;
}
