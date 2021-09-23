#pragma once

#include "TestNode.h"

class TestEnvironmentNode : public TestNode
{
public:
	TestEnvironmentNode();
	virtual ~TestEnvironmentNode();
protected:
	virtual void initNodes();
protected:

	void testMatrix();

	void testMultiPort();
};