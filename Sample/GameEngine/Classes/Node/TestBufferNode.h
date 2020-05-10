#pragma once

#include "TestFuncNode.h"

class TestBufferNode : public TestFuncNode
{
public:
	TestBufferNode();
	virtual ~TestBufferNode();
protected:
	virtual void testFunc();
};