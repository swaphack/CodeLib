#include "NodeExt.h"

#include "macros.h"

using namespace sys;
using namespace render;
using namespace ui;


NodeExt::NodeExt(Node* parent)
:_parent(parent)
{
	ASSERT(_parent != nullptr);

	_parent->addChild(this);
	this->setZOrder(NODE_EXT_ZORDER);
}

NodeExt::~NodeExt()
{

}

void NodeExt::draw()
{
	Node::draw();

	if (isBoxVisible())
	{
		GLTool::beginBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		GLTool::setColor(getBoxColor());
		GLTool::drawRect(&_parent->getRectVertex(), GL_LINE_LOOP);
		GLTool::endBlend();
	}
}