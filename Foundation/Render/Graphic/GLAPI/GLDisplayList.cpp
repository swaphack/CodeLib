#include "GLDisplayList.h"

using namespace render;

void GLDisplayList::newList(uint32_t list, InterleavedArrays type)
{
	glNewList(list, (GLenum)type);
}

void GLDisplayList::endList()
{
	glEndList();
}

void GLDisplayList::callList(uint32_t list)
{
	glCallList(list);
}

void GLDisplayList::callLists(int size, ListNameType type, const void* lists)
{
	glCallLists(size, (GLenum)type, lists);
}

int GLDisplayList::genLists(int range)
{
	return glGenLists(range);
}

int GLDisplayList::genList()
{
	return genLists(1);
}

void GLDisplayList::setListBase(uint32_t base)
{
	glListBase(base);
}

bool GLDisplayList::isList(uint32_t list)
{
	return glIsList(list) != 0;
}

void GLDisplayList::deleteLists(uint32_t list, int range)
{
	glDeleteLists(list, range);
}

void GLDisplayList::deleteList(uint32_t list)
{
	deleteLists(list, 1);
}
