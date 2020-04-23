#include "GLCallList.h"

using namespace render;

void GLCallList::newList(uint32_t list, InterleavedArrays type)
{
	glNewList(list, (GLenum)type);
}

void GLCallList::endList()
{
	glEndList();
}

void GLCallList::callList(uint32_t list)
{
	glCallList(list);
}

void GLCallList::callLists(int size, ListNameType type, const void* lists)
{
	glCallLists(size, (GLenum)type, lists);
}

int GLCallList::genLists(int range)
{
	return glGenLists(range);
}

int GLCallList::genList()
{
	return genLists(1);
}

void GLCallList::setListBase(uint32_t base)
{
	glListBase(base);
}

bool GLCallList::isList(uint32_t list)
{
	return glIsList(list) != 0;
}

void GLCallList::deleteLists(uint32_t list, int range)
{
	glDeleteLists(list, range);
}

void GLCallList::deleteList(uint32_t list)
{
	deleteLists(list, 1);
}
