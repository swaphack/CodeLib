#pragma once

#if (defined(_WIN32) || defined(WIN32))
#include <windows.h>
#endif

//#define USE_GLUT 1

#ifdef USE_GLUT

#define GLUT_DISABLE_ATEXIT_HACK
#include "opengl/GLUT.H"

#else

#include "opengl/GL.H"
#include "opengl/GLU.H"

#endif // USE_GLUT


#include "png/png.h"

#include "jpeg/jpeglib.h"