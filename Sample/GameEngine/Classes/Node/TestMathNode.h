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

	// ����
	void testMatrix();

	// ͶӰ
	void testProject();
private:
};
