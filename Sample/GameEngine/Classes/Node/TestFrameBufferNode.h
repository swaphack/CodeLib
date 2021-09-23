#pragma once

#include "../Env/TestNode.h"

class TestFrameBufferNode : public TestNode
{
public:
	TestFrameBufferNode();
	virtual~TestFrameBufferNode();
protected:
	virtual void initNodes();
protected:
	void testTextureFrameBuffer();
	void testPostProcessingNode();
private:
};