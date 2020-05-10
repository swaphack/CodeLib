#pragma once

#include "TestFuncNode.h"

class TestTextNode : public TestFuncNode
{
public:
	TestTextNode();
	virtual ~TestTextNode();
protected:
	virtual void testFunc();
private:
	void testTimeText();
	void testChineseText();
private:
};


