#include <stdio.h>

#include "WndRender.h"

int main(int argc, char** argv)
{
	int width = 1024;
	int height = 768;
	int millis = 17;

	glutInit(&argc, argv);
	render::GlutWindow* pWindow = new render::GlutWindow();
	pWindow->createWindow("OpenGL", width, height, millis, new WndRender());

	return 0;
}