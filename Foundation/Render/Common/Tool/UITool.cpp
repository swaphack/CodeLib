#include "Tool.h"

#include "UITool.h"

using namespace render;

void UITool::convertToOGLPoisition(float x, float y, float z, sys::Vector& dest)
{
	dest.x = x / Tool::getGLViewSize().width;
	dest.y = y / Tool::getGLViewSize().height;
	dest.z = z / Tool::getGLViewSize().deep;
}

sys::Vector UITool::convertToOGLPoisition(float x, float y, float z)
{
	return sys::Vector(x / Tool::getGLViewSize().width, y / Tool::getGLViewSize().height, z / Tool::getGLViewSize().deep);
}

sys::Vector UITool::convertToOGLPoisition(const sys::Vector& src)
{
	return sys::Vector(src.x / Tool::getGLViewSize().width, src.y / Tool::getGLViewSize().height, src.z / Tool::getGLViewSize().deep);
}

void UITool::convertToOGLPoisition(const sys::Vector& src, sys::Vector& dest)
{
	dest.x = src.x / Tool::getGLViewSize().width;
	dest.y = src.y / Tool::getGLViewSize().height;
	dest.z = src.z / Tool::getGLViewSize().deep;
}

sys::Vector UITool::convertToWindowPosition(float x, float y, float z)
{
	return sys::Vector(x * Tool::getGLViewSize().width, y * Tool::getGLViewSize().height, z * Tool::getGLViewSize().deep);
}

sys::Vector UITool::convertToWindowPosition(const sys::Vector& src)
{
	return sys::Vector(src.x * Tool::getGLViewSize().width, src.y * Tool::getGLViewSize().height, src.z * Tool::getGLViewSize().deep);
}