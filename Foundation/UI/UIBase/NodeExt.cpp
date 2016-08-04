#include "NodeExt.h"

#include "macros.h"

using namespace sys;
using namespace render;
using namespace ui;


NodeExt::NodeExt(Node* node)
:_pThis(node)
{

}

NodeExt::~NodeExt()
{

}

void NodeExt::draw()
{
	this->beginDraw();
	_pThis->draw();
	this->afterDraw();
}

UINameProtocol* NodeExt::getChildByName(const char* name)
{
	
}

void NodeExt::beginDraw()
{

}

void NodeExt::afterDraw()
{
	if (isBoxVisible())
	{
		GLTool::beginBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		GLTool::setColor(getBoxColor());
		GLTool::drawRect(&_pThis->getRectVertex(), GL_LINE_LOOP);
		GLTool::endBlend();
	}
}