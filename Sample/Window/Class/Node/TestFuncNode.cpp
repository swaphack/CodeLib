#include "TestFuncNode.h"

using namespace render;
TestFuncNode::TestFuncNode()
{

}

TestFuncNode::~TestFuncNode()
{

}

bool TestFuncNode::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto size = Tool::getGLViewSize();
	this->setAnchorPoint(math::Vector2(0, 0));
	this->setPosition(math::Vector2(0, 0));
	this->setVolume(size);

	this->testFunc();

	return true;
}

void TestFuncNode::testFunc()
{

}

