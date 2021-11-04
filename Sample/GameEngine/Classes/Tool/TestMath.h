#pragma once

#include "../Env/TestNode.h"

class TestMath : public TestNode
{
public:
	TestMath();
	virtual ~TestMath();
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
