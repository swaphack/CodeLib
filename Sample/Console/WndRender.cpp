#include "WndRender.h"

using namespace render;
using namespace sys;
using namespace ui;

WndRender::WndRender()
{
	this->getCanvas()->setDimensions(render::ED_2D);
}

WndRender::~WndRender()
{
	
}

void WndRender::show()
{
	testProgram();
}

void WndRender::testProgram()
{
	CtrlImage* pImage = CREATE_NODE(CtrlImage);
	pImage->setImagePath("Resource/Image/NeHe.png");
	pImage->setPosition(512, 400, 0);
	pImage->setScale(1, 1, 1);
	pImage->setRotation(0, 0, 30);
	this->getCanvas()->getRoot()->addChild(pImage);

	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->load("Resource/shader/gray.vsh", "Resource/shader/gray.fsh");
	pProgram->link();
	pImage->setProgram(pProgram);
}
