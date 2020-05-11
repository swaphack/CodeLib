#pragma once

#include "TestFuncNode.h"

class TestFragmentNode : public TestFuncNode
{
public:
	TestFragmentNode();
	virtual ~TestFragmentNode();
protected:
	virtual void testFunc();
private:
	void testStencil();
};