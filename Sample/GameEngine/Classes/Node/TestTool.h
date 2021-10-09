#pragma once

#include "../Env/TestNode.h"

class TestTool : public TestNode
{
public:
	TestTool();
	virtual ~TestTool();
protected:
	virtual void initNodes();
private:
	void testTexturePack();
};