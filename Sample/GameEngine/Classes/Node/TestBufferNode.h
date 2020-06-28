#pragma once

#include "TestNode.h"

class TestBufferNode : public TestNode
{
public:
	TestBufferNode();
	virtual ~TestBufferNode();
protected:
	virtual void initNodes();
};