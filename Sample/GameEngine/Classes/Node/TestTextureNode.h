#pragma once

#include "../Env/TestNode.h"

class TestTextureNode : public TestNode
{
public:
	TestTextureNode();
	virtual ~TestTextureNode();
protected:
	virtual void initNodes();
private:
	void testMultiTexture();
};
