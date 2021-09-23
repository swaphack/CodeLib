#pragma once

#include "../Env/TestNode.h"

class TestBufferNode : public TestNode
{
public:
	TestBufferNode();
	virtual ~TestBufferNode();
protected:
	virtual void initNodes();
};