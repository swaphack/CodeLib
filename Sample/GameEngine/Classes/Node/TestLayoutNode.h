#pragma once

#include "TestNode.h"

class TestLayoutNode : public TestNode
{
public:
	TestLayoutNode();
	virtual ~TestLayoutNode();
protected:
	virtual void initNodes();
private:
	void testLayout();
};