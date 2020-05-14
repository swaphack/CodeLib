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
	CameraDimensions d = CameraDimensions::D2;
	Camera::setMainCamera(d);

	getCanvas()->pushScene(CREATE_NODE(TestMainScene));
}

