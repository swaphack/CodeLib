#pragma once

#include "../Env/TestNode.h"

class TestMathNode : public TestNode
{
public:
	TestMathNode();
	virtual ~TestMathNode();
protected:
	virtual void initNodes();
protected:
	void testMath();

	// æÿ’Û
	void testMatrix();

	// Õ∂”∞
	void testProject();
private:
};
