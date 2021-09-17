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
	void init3DSkyBox();
	void init2DSkyBox();

	void addGrid();

	void testMatrix();

	void testMultiPort();
};