#pragma once

#include "TestFuncNode.h"

class TestMediaNode : public TestFuncNode
{
public:
	TestMediaNode();
	virtual ~TestMediaNode();
protected:
	virtual void testFunc();
private:
	void testMedia();
private:
};


