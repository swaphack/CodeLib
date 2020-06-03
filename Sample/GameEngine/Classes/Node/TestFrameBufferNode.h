#pragma once

#include "TestFuncNode.h"

class TestFrameBufferNode : public TestFuncNode
{
public:
	TestFrameBufferNode();
	virtual~TestFrameBufferNode();
protected:
	virtual void testFunc();
protected:
	void testTextureFrameBuffer();
	void testPostProcessingNode();
private:
};