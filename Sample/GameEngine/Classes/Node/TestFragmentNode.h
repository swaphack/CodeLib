#pragma once

#include "../Env/TestNode.h"

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