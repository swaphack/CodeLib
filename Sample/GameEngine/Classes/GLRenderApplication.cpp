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
	CameraDimensions d = CameraDimensions::TWO;
	Camera::setMainCamera(d);

	getCanvas()->pushScene(CREATE_NODE(TestMainScene));
}

