#include "WndRender.h"
#include "ShaderScene.h"
#include "MainScene.h"
#include "render.h"

using namespace render;

WndRender::WndRender()
{
	
}

WndRender::~WndRender()
{
	
}

void WndRender::show()
{
	CameraDimensions d = ED_2D;
	Camera::setMainCamera(d);
	getCanvas()->pushScene(CREATE_NODE(ShaderScene));
	//getCanvas()->pushScene(CREATE_NODE(MainScene));
}

