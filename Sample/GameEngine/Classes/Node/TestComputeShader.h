#pragma once

#include "../Env/TestNode.h"

class TestComputeShader : public TestNode
{
public:
	TestComputeShader();
	virtual ~TestComputeShader();
protected:
	virtual void initNodes();
private:
	void testSimpleComputeShader();

	void testParticleNode();

	void testCalulate();
};
