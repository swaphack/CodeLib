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

	auto size = Tool::getGLViewSize();
	this->setAnchorPoint(math::Vector2(0, 0));
	this->setPosition(math::Vector2(0, 0));
	this->setVolume(size);

	this->initNodes();

	return true;
}

void TestNode::initNodes()
{

}

