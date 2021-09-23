#pragma once

#include "../Env/TestNode.h"

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
