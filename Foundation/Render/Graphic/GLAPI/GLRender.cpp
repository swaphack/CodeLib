#include "GLRender.h"

using namespace render;

void GLRender::setRenderMode(RenderingMode mode)
{
	glRenderMode((GLenum)mode);
}
void GLRender::setRenderMode()
{
	setRenderMode(RenderingMode::RENDER);
}

void GLRender::setSelectMode()
{
	setRenderMode(RenderingMode::SELECT);
}

void GLRender::getSelectBuffer(int size, uint32_t* buffer)
{
	glSelectBuffer(size, buffer);
}

void GLRender::initNames()
{
	glInitNames();
}

void GLRender::loadName(int name)
{
	glLoadName(name);
}

void GLRender::pushName(int name)
{
	glPushName(name);
}

void GLRender::popName()
{
	glPopName();
}

void GLRender::setFeedbackMode()
{
	setRenderMode(RenderingMode::FEEDBACK);
}

void GLRender::getFeedBackBuffer(int size, FeedBackMode mode, float* buffer)
{
	glFeedbackBuffer(size, (GLenum)mode, buffer);
}

void GLRender::setPassThrough(float value)
{
	glPassThrough(value);
}
