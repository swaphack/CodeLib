#include "GLVertexArrays.h"

using namespace render;

void GLVertexArrays::genVertexArrays(int size, uint32_t* ary)
{
	glGenVertexArrays(size, ary);
}

void GLVertexArrays::bindVertexArrays(uint32_t ary)
{
	glBindVertexArray(ary);
}

void GLVertexArrays::deleteVertexArrays(int size, const uint32_t* ary)
{
	glDeleteVertexArrays(size, ary);
}

bool GLVertexArrays::isVertexArrays(uint32_t ary)
{
	return glIsVertexArray(ary) == 1;
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
