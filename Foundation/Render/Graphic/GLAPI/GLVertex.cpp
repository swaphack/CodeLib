#include "GLVertex.h"
#include "GLState.h"

using namespace render;

void GLVertex::beginMode(ShapeMode mode)
{
	glBegin((GLenum)mode);
}

void GLVertex::endMode()
{
	glEnd();
}

void GLVertex::setVertex(float x, float y, float z)
{
	glVertex3f(x, y, z);
}

void GLVertex::setVertex(const math::Vector3& value)
{
	glVertex3f(value.getX(), value.getY(), value.getZ());
}

void GLVertex::setNormal(const math::Vector3& value)
{
	setNormal(value.getX(), value.getY(), value.getZ());
}

void GLVertex::setNormal(float x, float y, float z)
{
	glNormal3f(x, y, z);
}

void GLVertex::setColor(float r, float g, float b, float a)
{
	glColor4f(r, g, b, a);
}

void GLVertex::setColor(const sys::Color3F& value, float opacity)
{
	float r = value.red* opacity;
	float g = value.green* opacity;
	float b = value.blue* opacity;
	setColor(r, g, b);
}

void GLVertex::setColor(const sys::Color4F& value, float opacity)
{
	float r = value.red* opacity;
	float g = value.green* opacity;
	float b = value.blue* opacity;
	float a = value.alpha * opacity;

	setColor(r, g, b, a);

	setColor(value.red * opacity, value.green* opacity, value.blue* opacity, value.alpha* opacity);
}

void GLVertex::setColor(const sys::Color3B& value, uint8_t opacity)
{
	float v = powf(COLOR_FLOAT_VALUE, 2);
	float r = value.red * opacity / v;
	float g = value.green * opacity / v;
	float b = value.blue * opacity / v;

	setColor(r, g, b);
}

void GLVertex::setColor(const sys::Color4B& value, uint8_t opacity)
{
	float v = powf(COLOR_FLOAT_VALUE, 2);
	float r = value.red * opacity / v;
	float g = value.green * opacity / v;
	float b = value.blue * opacity / v;
	float a = value.alpha * opacity / v;

	setColor(r, g, b, a);
}

void GLVertex::setTexCoord1D(float s)
{
	glTexCoord1f(s);
}

void GLVertex::setTexCoord2D(float s, float t)
{
	glTexCoord2f(s, t);
}

void GLVertex::setTexCoord2D(const math::Vector2& value)
{
	setTexCoord2D(value.getX(), value.getY());
}

void GLVertex::setVertexPointer(int size, DataType type, int stride, const void* value)
{
	glVertexPointer(size, (GLenum)type, stride, value);
}

void GLVertex::setColorPointer(int size, DataType type, int stride, const void* value)
{
	glColorPointer(size, (GLenum)type, stride, value);
}

void GLVertex::setNormalPointer(DataType type, int stride, const void* value)
{
	glNormalPointer((GLenum)type, stride, value);
}

void GLVertex::setTexCoordPointer(int size, DataType type, int stride, const void* value)
{
	glTexCoordPointer(size, (GLenum)type, stride, value);
}

void GLVertex::setIndexPointer(IndexPointerType type, int stride, const void* value)
{
	glIndexPointer((GLenum)type, stride, value);
}

void GLVertex::setVertexPointer2(DataType type, int stride, const void* value)
{
	setVertexPointer(2, type, stride, value);
}

void GLVertex::setVertexPointer3(DataType type, int stride, const void* value)
{
	setVertexPointer(3, type, stride, value);
}

void GLVertex::setVertexPointer4(DataType type, int stride, const void* value)
{
	setVertexPointer(4, type, stride, value);
}

void GLVertex::setColorPointer3(DataType type, int stride, const void* value)
{
	setColorPointer(3, type, stride, value);
}

void GLVertex::setColorPointer4(DataType type, int stride, const void* value)
{
	setColorPointer(4, type, stride, value);
}

void GLVertex::setTexCoordPointer1(DataType type, int stride, const void* value)
{
	setTexCoordPointer(1, type, stride, value);
}

void GLVertex::setTexCoordPointer2(DataType type, int stride, const void* value)
{
	setTexCoordPointer(2, type, stride, value);
}

void GLVertex::setTexCoordPointer3(DataType type, int stride, const void* value)
{
	setTexCoordPointer(3, type, stride, value);
}

void GLVertex::setTexCoordPointer4(DataType type, int stride, const void* value)
{
	setTexCoordPointer(4, type, stride, value);
}

void GLVertex::drawArrayElement(int index)
{
	glArrayElement(index);
}

void GLVertex::drawArrays(ShapeMode mode, int first, int count)
{
	glDrawArrays((GLenum)mode, first, count);
}

void GLVertex::drawElements(ShapeMode mode, int count, IndexDataType type, const void* data)
{
	glDrawElements((GLenum)mode, count, (GLenum)type, data);
}

void GLVertex::setEdgeFlag(bool flag)
{
	glEdgeFlag(flag);
}

void GLVertex::setEdgeFlagPointer(int stride, const void* flag)
{
	glEdgeFlagPointer(stride, flag);
}

void GLVertex::setIndex(int index)
{
	glIndexi(index);
}

void GLVertex::setInterleavedArrays(InterleavedArraysMode mode, int stride, const void* value)
{
	glInterleavedArrays((GLenum)mode, stride, value);
}

void GLVertex::setTexCoord3D(float s, float t, float r)
{
	glTexCoord3f(s, t, r);
}

void GLVertex::setTexCoord3D(const math::Vector2& value)
{
	setTexCoord3D(value.getX(), value.getY(), value.getSize());
}

void GLVertex::drawRect(const RectVertex& value)
{
	beginMode(ShapeMode::QUADS);

	setVertex(value.leftDown);
	setVertex(value.rightDown);
	setVertex(value.rightUp);
	setVertex(value.leftUp);

	endMode();
}

void GLVertex::drawTextureRect(const TextureRectVertex& value)
{
	GLState::enableClientState(ClientArrayType::VERTEX_ARRAY);
	GLVertex::setVertexPointer(3, DataType::FLOAT, 0, value.vertices);

	GLState::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLVertex::setTexCoordPointer(2, DataType::FLOAT, 0, value.uvs);

	GLState::enableClientState(ClientArrayType::COLOR_ARRAY);
	GLVertex::setColorPointer(4, DataType::FLOAT, 0, value.colors);

	GLVertex::drawElements(ShapeMode::TRIANGLES, 6, IndexDataType::UNSIGNED_SHORT, value.indices);

	GLState::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLState::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLState::disableClientState(ClientArrayType::COLOR_ARRAY);
}

