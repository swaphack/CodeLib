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
	DimensionsType eType = DimensionsType::TWO;
	Camera::getMainCamera()->setDimensions(eType);

	getCanvas()->pushScene(CREATE_NODE(TestMainScene));
}

