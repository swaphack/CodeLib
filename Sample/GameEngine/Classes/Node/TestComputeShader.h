#pragma once

#include "TestFuncNode.h"

class TestComputeShader : public TestFuncNode
{
public:
	TestComputeShader();
	virtual ~TestComputeShader();
protected:
	virtual void testFunc();
private:
	void testSimpleComputeShader();

	void testParticleNode();
};
