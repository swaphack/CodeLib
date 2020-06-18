#pragma once

#include "TestFuncNode.h"

class TestPostProcessing : public TestFuncNode
{
public:
	TestPostProcessing();
	virtual ~TestPostProcessing();
protected:
	virtual void testFunc();
private:
	void testSimplePostProcessing();

	void testImage();

	render::CtrlImage* createImage();
};
