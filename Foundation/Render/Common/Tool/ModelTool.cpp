#include "ModelTool.h"
#include "Tool.h"

using namespace render;

sys::Volume ModelTool::convertToOGLVolume(const sys::Volume& src)
{
	return sys::Volume(src.width / Tool::getGLViewSize().width * 2 - 1, src.height / Tool::getGLViewSize().height * 2 - 1, src.deep);
}