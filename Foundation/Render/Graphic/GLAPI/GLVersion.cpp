#include "GLVersion.h"
#include "macros.h"
#include "system.h"

using namespace render;

void GLVersion::showDetail()
{
	PRINT("OpenGL vendor string: %s\n", glGetString(GL_VENDOR));
	PRINT("OpenGL renderer string: %s\n", glGetString(GL_RENDERER));
	PRINT("OpenGL version string: %s\n", glGetString(GL_VERSION));
	PRINT("OpenGL shader language string: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//PRINT("OpenGL extensions string: %s\n", glGetString(GL_EXTENSIONS));
	PRINT("============================\n");
}


