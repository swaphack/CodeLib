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
	CameraDimensions d = CameraDimensions::THREE;
	Camera::getMainCamera()->setDimensions(d);

	getCanvas()->pushScene(CREATE_NODE(TestMainScene));
}

