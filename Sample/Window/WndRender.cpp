#include "WndRender.h"
#include "MainScene.h"

#include "ui.h"
#include "algorithm.h"
#include "render.h"

using namespace render;
using namespace sys;
using namespace ui;

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
	getCanvas()->pushScene(CREATE_NODE(MainScene));
}

