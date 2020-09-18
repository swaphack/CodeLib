#pragma once

#include "TestNode.h"

class TestPostProcessing : public TestNode
{
public:
	TestPostProcessing();
	virtual ~TestPostProcessing();
protected:
	virtual void initNodes();
private:
	void testFramePostProcessing();

	void testPixelPostProcessing();

	void testImage();
};
