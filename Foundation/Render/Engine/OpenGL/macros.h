#pragma once

#include "../../Graphic/import.h"
#include "opengl.h"


#define SHOW_OPENGL_ERROR_MESSAGE() {int error = glGetError(); PRINT("OpenGL error %d\n", error);}