#include "UINode.h"

using namespace render;


UINode::UINode()
:_bShowRect(false)
, _name("")
{

}

UINode::~UINode()
{

}

void UINode::draw()
{
	this->beginDrawUI();
	this->onDrawUI();
	this->afterDrawUI();
}

void UINode::setRectVisible(bool status)
{
	_bShowRect = status;
}

bool UINode::isRectVisible()
{
	return _bShowRect;
}

void UINode::setRectColor(const sys::Color4B& color)
{
	_rectColor = color;
}

sys::Color4B UINode::getRectColor()
{
	return _rectColor;
}


void render::UINode::setName(const char* name)
{
	_name = name;
}

const char* render::UINode::getName()
{
	return _name.c_str();
}

UINode* UINode::getChildByName(const char* name)
{
	UINode* node = nullptr;
	std::vector<Object*>::iterator iter = _children.begin();
	while (iter != _children.end())
	{
		node = dynamic_cast<UINode*>((*iter));
		if (node && strcmp(node->getName(), name) == 0)
		{
			return node;
		}
		iter++;
	}

	return nullptr;
}

void UINode::beginDrawUI()
{

}

void UINode::onDrawUI()
{

}

void UINode::afterDrawUI()
{
	this->drawRect();
}

void UINode::drawRect()
{
	if (_bShowRect)
	{
		GLTool::beginBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		GLTool::setColor(_rectColor);
		GLTool::drawRect(&_rectVertex, GL_LINE_LOOP);
		GLTool::endBlend();
	}
}