#include "GLRasterization.h"

using namespace render;

void GLRasterization::drawBitMap(int width, int heith, float xorig, float yorig, float xmove, float ymove, const uint8_t* value)
{
	glBitmap(width, heith, xorig, yorig, xmove, ymove, value);
}

void GLRasterization::clearIndex(int mask)
{
	glClearIndex(mask);
}

void GLRasterization::setClipPlane(ClipPlaneName name, const double* equation)
{
	glClipPlane((GLenum)name, equation);
}

void GLRasterization::copyPixels(float x, float y, int width, int height, PixelCopyType copyType)
{
	glCopyPixels(x, y, width, height, (GLenum)copyType);
}

void GLRasterization::drawPixels(int width, int heith, TextureDataFormat format, TextureDataType type, const void* value)
{
	glDrawPixels(width, heith, (GLenum)format, (GLenum)type, value);
}

void GLRasterization::getFeedBackBuffer(int size, FeedBackMode mode, float* buffer)
{
	glFeedbackBuffer(size, (GLenum)mode, buffer);
}

void GLRasterization::getClipPlane(ClipPlaneName name, double* equation)
{
	glGetClipPlane((GLenum)name, equation);
}

void GLRasterization::getMap(MapTarget target, GetMapTarget parameter, float* value)
{
	glGetMapfv((GLenum)target, (GLenum)parameter, value);
}

void GLRasterization::getPixelMap(PixelMap map, float* value)
{
	glGetPixelMapfv((GLenum)map, value);
}

void GLRasterization::getPolygonStipple(uint8_t* mask)
{
	glGetPolygonStipple(mask);
}

void GLRasterization::initNames()
{
	glInitNames();
}

void GLRasterization::loadName(int name)
{
	glLoadName(name);
}

void GLRasterization::pushName(int name)
{
	glPushName(name);
}

void GLRasterization::popName()
{
	glPopName();
}

void GLRasterization::setLineStipple(int factor, uint16_t pattern)
{
	glLineStipple(factor, pattern);
}

void GLRasterization::setPassThrough(float value)
{
	glPassThrough(value);
}

void GLRasterization::setRasterPos(float x, float y, float z /*= 0*/)
{
	glRasterPos3f(x, y, z);
}

void GLRasterization::setRect(float x1, float y1, float x2, float y2)
{
	glRectf(x1, y1, x2, y2);
}

void GLRasterization::setRect(const math::Vector2& src, const math::Vector2& dest)
{
	setRect(src.getX(), src.getY(), dest.getX(), dest.getY());
}

void GLRasterization::setRect(const math::Vector2& src, const math::Size& size)
{
	setRect(src.getX(), src.getY(), src.getX() + size.getWidth(), src.getY() + size.getHeight());
}

void GLRasterization::setPixelZoom(float x, float y)
{
	glPixelZoom(x, y);
}

void GLRasterization::setPolygonStripple(const uint8_t *mask)
{
	glPolygonStipple(mask);
}

void GLRasterization::setRenderMode(RenderingMode mode)
{
	glRenderMode((GLenum)mode);
}
void GLRasterization::setRenderMode()
{
	setRenderMode(RenderingMode::RENDER);
}

void GLRasterization::setSelectMode()
{
	setRenderMode(RenderingMode::SELECT);
}

void GLRasterization::getSelectBuffer(int size, uint32_t* buffer)
{
	glSelectBuffer(size, buffer);
}

void GLRasterization::setFeedbackMode()
{
	setRenderMode(RenderingMode::FEEDBACK);
}

void GLRasterization::setWindowPos(float x, float y, float z /*= 0*/)
{
	glWindowPos3f(x, y, z);
}
