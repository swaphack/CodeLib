#include "UINode.h"

using namespace render;


UINode::UINode()
{

}

UINode::~UINode()
{

}

void UINode::draw()
{
	this->beginDrawUI();
	Node::draw();
	this->afterDrawUI();
}

UINameProtocol* UINode::getChildByName(const char* name)
{
	UINameProtocol* node = nullptr;
	std::vector<Object*>::iterator iter = _children.begin();
	while (iter != _children.end())
	{
		node = dynamic_cast<UINameProtocol*>((*iter));
		if (node && strcmp(node->getName(), name) == 0)
		{
			return node;
		}
		iter++;
	}

	return nullptr;
}

void UINode::afterDrawUI()
{
	if (isBoxVisible())
	{
		GLTool::beginBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		GLTool::setColor(getBoxColor());
		GLTool::drawRect(&_rectVertex, GL_LINE_LOOP);
		GLTool::endBlend();
	}
}