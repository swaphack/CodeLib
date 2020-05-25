#pragma once

#include "TestFuncNode.h"

class TestTextureNode : public TestFuncNode
{
public:
	TestTextureNode();
	virtual ~TestTextureNode();
protected:
	virtual void testFunc();
private:
	void testMultiTexture();
};
