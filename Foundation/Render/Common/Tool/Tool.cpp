#include "Tool.h"
#include <cmath>

using namespace render;

sys::Volume Tool::GL_VIEW_SIZE = sys::Volume();

void Tool::setGLViewSize(float width, float height)
{
	GL_VIEW_SIZE.width = width;
	GL_VIEW_SIZE.height = height;

	GL_VIEW_SIZE.deep = width > height ? width : height;
}

const sys::Volume& Tool::getGLViewSize()
{
	return GL_VIEW_SIZE;
}

sys::Vector Tool::convertToRadian(const sys::Vector& src)
{
	return sys::Vector(src.x / (float)180 * PI, src.y / (float)180 * PI, src.z / (float)180 * PI);
}

sys::Vector Tool::convertToAngle(const sys::Vector& src)
{
	return sys::Vector(src.x / PI * (float)180, src.y / PI * (float)180, src.z / PI * (float)180);
}

//////////////////////////////////////////////////////////////////////////

sys::Volume ModelTool::convertToOGLVolume(const sys::Volume& src)
{
	return sys::Volume(src.width / Tool::getGLViewSize().width * 2 - 1, src.height / Tool::getGLViewSize().height * 2 - 1, src.deep);
}
