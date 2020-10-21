#pragma once

#include "TestNode.h"

class TestMathNode : public TestNode
{
public:
	TestMathNode();
	virtual ~TestMathNode();
protected:
	virtual void initNodes();
protected:
	void testMath();

	void testMatrix();
private:
};
