#include "GLVersion.h"
#include "macros.h"
#include "system.h"

using namespace render;

int GLVersion::getVersionID()
{
	GLint version;
	glGetIntegerv(GL_VERSION, &version);
	return version;
}

std::string GLVersion::getVersionDetail()
{
	char* text = (char*)glGetString(GL_VERSION);
	if (text == nullptr)
	{
		return "";
	}

	return std::string(text);
}

std::string GLVersion::getRendererDetail()
{
	char* text = (char*)glGetString(GL_RENDERER);
	if (text == nullptr)
	{
		return "";
	}

	return std::string(text);
}

std::string GLVersion::getVendorDetail()
{
	char* text = (char*)glGetString(GL_VENDOR);
	if (text == nullptr)
	{
		return "";
	}

	return std::string(text);
}

void GLVersion::showDetail()
{
	PRINT("OpenGL vendor string: %s\n", glGetString(GL_VENDOR));
	PRINT("OpenGL renderer string: %s\n", glGetString(GL_RENDERER));
	PRINT("OpenGL version string: %s\n", glGetString(GL_VERSION));
}
