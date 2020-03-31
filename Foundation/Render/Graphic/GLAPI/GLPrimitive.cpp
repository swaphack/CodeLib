#include "GLPrimitive.h"
using namespace render;


void GLPrimitive::setClipPlane(ClipPlaneName name, const double* equation)
{
	glClipPlane((GLenum)name, equation);
}

void GLPrimitive::setDepthRange(float zNear, float zFar)
{
	glDepthRange(zNear, zFar);
}

void GLPrimitive::loadFrustum(float left, float right, float bottom, float top, float zNear, float zFar)
{
	glFrustum(left, right, bottom, top, zNear, zFar);
}

void GLPrimitive::loadOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	glOrtho(left, right, bottom, top, zNear, zFar);
}

void GLPrimitive::setViewport(float x, float y, float width, float height)
{
	glViewport(x, y, width, height);
}

void GLPrimitive::setPointSize(float size)
{
	glPointSize(size);
}

void GLPrimitive::setLineWidth(float width)
{
	glLineWidth(width);
}

void GLPrimitive::setLineStipple(int factor, uint16_t pattern)
{
	glLineStipple(factor, pattern);
}

void GLPrimitive::setPolygonStripple(const uint8_t *mask)
{
	glPolygonStipple(mask);
}

void GLPrimitive::setPixelStore(PixelStore name, float value)
{
	glPixelStoref((GLenum)name, value);
}

void GLPrimitive::setPixelTransfer(PixelTransfer name, float value)
{
	glPixelTransferf((GLenum)name, value);
}

void GLPrimitive::setPixelMap(PixelMap name, int size, const float* value)
{
	glPixelMapfv((GLenum)name, size, value);
}

void GLPrimitive::setRasterPos(float x, float y, float z /*= 0*/)
{
	glRasterPos3f(x, y, z);
}

void GLPrimitive::setRect(float x, float y, float w, float h)
{
	glRectf(x, y, w, h);
}

void GLPrimitive::setPixelZoom(float x, float y)
{
	glPixelZoom(x, y);
}

void GLPrimitive::drawPixels(float width, float heith, PixelFormat format, PixelType type, const void* value)
{
	glDrawPixels(width, heith, (GLenum)format, (GLenum)type, value);
}

void GLPrimitive::drawBitMap(float width, float heith, float xorig, float yorig, float xmove, float ymove, const uint8_t* value)
{
	glBitmap(width, heith, xorig, yorig, xmove, ymove, value);
}

void GLPrimitive::setPolygonOffset(float factor, float units)
{
	glPolygonOffset(factor, units);
}

void GLPrimitive::setFrontFace(FrontFaceDirection mode)
{
	glFrontFace((GLenum)mode);
}

void GLPrimitive::setCullFace(CullFaceMode mode)
{
	glCullFace((GLenum)mode);
}


