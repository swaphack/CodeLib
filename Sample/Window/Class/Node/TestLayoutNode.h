#pragma once

#include "TestFuncNode.h"

class TestLayoutNode : public TestFuncNode
{
public:
	TestLayoutNode();
	virtual ~TestLayoutNode();
protected:
	virtual void testFunc();
private:
	void testLayout();
};