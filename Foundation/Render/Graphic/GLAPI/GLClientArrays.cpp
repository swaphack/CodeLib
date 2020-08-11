#include "GLClientArrays.h"

using namespace render;

void GLClientArrays::enableClientState(ClientArrayType type)
{
	glEnableClientState((GLenum)type);
}

void GLClientArrays::disableClientState(ClientArrayType type)
{
	glDisableClientState((GLenum)type);
}

void GLClientArrays::setVertexPointer(int size, DataType type, int stride, const void* value)
{
	glVertexPointer(size, (GLenum)type, stride, value);
}

void GLClientArrays::setColorPointer(int size, DataType type, int stride, const void* value)
{
	glColorPointer(size, (GLenum)type, stride, value);
}

void GLClientArrays::setNormalPointer(DataType type, int stride, const void* value)
{
	glNormalPointer((GLenum)type, stride, value);
}

void GLClientArrays::setTexCoordPointer(int size, DataType type, int stride, const void* value)
{
	glTexCoordPointer(size, (GLenum)type, stride, value);
}

void GLClientArrays::setIndexPointer(IndexPointerType type, int stride, const void* value)
{
	glIndexPointer((GLenum)type, stride, value);
}

void GLClientArrays::setInterleavedArrays(InterleavedArraysMode mode, int stride, const void* value)
{
	glInterleavedArrays((GLenum)mode, stride, value);
}

void GLClientArrays::setVertexPointer2(DataType type, int stride, const void* value)
{
	setVertexPointer(2, type, stride, value);
}

void GLClientArrays::setVertexPointer3(DataType type, int stride, const void* value)
{
	setVertexPointer(3, type, stride, value);
}

void GLClientArrays::setVertexPointer4(DataType type, int stride, const void* value)
{
	setVertexPointer(4, type, stride, value);
}

void GLClientArrays::setColorPointer3(DataType type, int stride, const void* value)
{
	setColorPointer(3, type, stride, value);
}

void GLClientArrays::setColorPointer4(DataType type, int stride, const void* value)
{
	setColorPointer(4, type, stride, value);
}

void GLClientArrays::setTexCoordPointer1(DataType type, int stride, const void* value)
{
	setTexCoordPointer(1, type, stride, value);
}

void GLClientArrays::setTexCoordPointer2(DataType type, int stride, const void* value)
{
	setTexCoordPointer(2, type, stride, value);
}

void GLClientArrays::setTexCoordPointer3(DataType type, int stride, const void* value)
{
	setTexCoordPointer(3, type, stride, value);
}

void GLClientArrays::setTexCoordPointer4(DataType type, int stride, const void* value)
{
	setTexCoordPointer(4, type, stride, value);
}

void GLClientArrays::setFogCoordPointer(int stride, const void* value)
{
	glFogCoordPointer((GLenum)DataType::FLOAT, stride, value);
}

void GLClientArrays::setSecondaryColorPointer(DataType type, int stride, const void* value)
{
	glSecondaryColorPointer(3, (GLenum)type, stride, value);
}

void GLClientArrays::pushClientAttrib(ClientAttribMask value)
{
	glPushClientAttrib((uint32_t)value);
}

void GLClientArrays::popClientAttrib()
{
	glPopClientAttrib();
}

void GLClientArrays::multiTexCoord(ActiveTextureName texture, float s, float t)
{
	glMultiTexCoord2f((GLenum)texture, s, t);
}

void GLClientArrays::setEdgeFlagPointer(int stride, const void* flag)
{
	glEdgeFlagPointer(stride, flag);
}

void GLClientArrays::drawArrayElement(int index)
{
	glArrayElement(index);
}

void GLClientArrays::drawArrays(DrawMode mode, int first, int count)
{
	glDrawArrays((GLenum)mode, first, count);
}

void GLClientArrays::drawElements(DrawMode mode, int count, IndexDataType type, const void* data)
{
	glDrawElements((GLenum)mode, count, (GLenum)type, data);
}

void render::GLClientArrays::setTangentPointer(DataType type, int stride, const void* value)
{
	if (glTangentPointerEXT)
	{
		glTangentPointerEXT((GLenum)type, stride, (void*)value);
	}
}

void render::GLClientArrays::setBitangentPointer(DataType type, int stride, const void* value)
{
	if (glBinormalPointerEXT)
	{
		glBinormalPointerEXT((GLenum)type, stride, (void*)value);
	}
}
