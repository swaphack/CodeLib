#pragma once

#include "../Env/TestNode.h"

class TestDrawNode : public TestNode
{
public:
	TestDrawNode();
	virtual ~TestDrawNode();
protected:
	virtual void initNodes();
private:
	void testDrawNode();
};