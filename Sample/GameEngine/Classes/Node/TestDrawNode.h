#pragma once

#include "TestFuncNode.h"

class TestDrawNode : public TestFuncNode
{
public:
	TestDrawNode();
	virtual ~TestDrawNode();
protected:
	virtual void testFunc();
private:
	void testDrawNode();
};