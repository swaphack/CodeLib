#include "GLUtility.h"

using namespace render;

const uint8_t* GLUtility::getString(StringName name)
{
	return glGetString((GLenum)name);
}

