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

	this->testFunc();

	return true;
}

void TestFuncNode::testFunc()
{

}

