#include "GLRenderApplication.h"
#include "Scene/TestMainScene.h"
#include "render.h"

using namespace render;

GLRenderApplication::GLRenderApplication()
{
	
}

GLRenderApplication::~GLRenderApplication()
{
	
}

void GLRenderApplication::show()
{
	getCanvas()->pushScene(CREATE_NODE(TestMainScene));
}

