#pragma once

#include "TestNode.h"

class TestDrawNode : public TestNode
{
public:
	TestDrawNode();
	virtual ~TestDrawNode();
protected:
	virtual void initNodes();
private:
	void testDrawNode();
};