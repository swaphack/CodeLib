#include "TestNode.h"

using namespace render;
TestNode::TestNode()
{

}

TestNode::~TestNode()
{

}

bool TestNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto size = Tool::getViewSize();
	this->setAnchorPoint(math::Vector2(0, 0));
	this->setPosition(math::Vector2(-0.5f* size.getWidth(), -0.5f * size.getHeight()));
	this->setVolume(size);

	this->initNodes();

	return true;
}

void TestNode::initNodes()
{

}

