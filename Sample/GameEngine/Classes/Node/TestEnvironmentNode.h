#pragma once

#include "TestFuncNode.h"

class TestEnvironmentNode : public TestFuncNode
{
public:
	TestEnvironmentNode();
	virtual ~TestEnvironmentNode();
protected:
	virtual void testFunc();

protected:
	void init3DSkyBox();
	void init2DSkyBox();
};