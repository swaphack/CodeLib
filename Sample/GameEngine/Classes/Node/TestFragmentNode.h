#pragma once

#include "TestNode.h"

class TestFragmentNode : public TestNode
{
public:
	TestFragmentNode();
	virtual ~TestFragmentNode();
protected:
	virtual void initNodes();
private:
	void testStencil();
};