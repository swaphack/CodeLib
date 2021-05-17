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
	DimensionsType eType = DimensionsType::THREE;
	Camera::getMainCamera()->setDimensions(eType);

	getCanvas()->pushScene(CREATE_NODE(TestMainScene));
}

