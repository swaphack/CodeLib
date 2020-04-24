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

void GLVertex::setEdgeFlag(bool flag)
{
	glEdgeFlag(flag);
}

void GLVertex::setIndex(int index)
{
	glIndexi(index);
}

void GLVertex::setTexCoord3D(float s, float t, float r)
{
	glTexCoord3f(s, t, r);
}

void GLVertex::setTexCoord3D(const math::Vector2& value)
{
	setTexCoord3D(value.getX(), value.getY(), value.getSize());
}

