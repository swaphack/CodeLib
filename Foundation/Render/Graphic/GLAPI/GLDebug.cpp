#include "GLDebug.h"
#include "macros.h"
#include "system.h"

using namespace render;

#define SHOW_ERROR_CODE(EID, CODE)  \
	if (EID == CODE) PRINT("OpenGL error id %d, message: %s.\n", CODE, #CODE);

void GLDebug::showError()
{
	int errID = glGetError();
	if (errID == 0)
	{
		return;
	}
	PRINT("OpenGL Error=============\n");
	SHOW_ERROR_CODE(errID, GL_INVALID_ENUM);
	SHOW_ERROR_CODE(errID, GL_INVALID_VALUE);
	SHOW_ERROR_CODE(errID, GL_INVALID_OPERATION);
	SHOW_ERROR_CODE(errID, GL_STACK_OVERFLOW);
	SHOW_ERROR_CODE(errID, GL_STACK_UNDERFLOW);
	SHOW_ERROR_CODE(errID, GL_OUT_OF_MEMORY);
#if _DEBUG
	//ASSERT(errID == 0);
#endif
}
