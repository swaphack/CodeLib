#pragma once

#include "TestNode.h"

class TestMediaNode : public TestNode
{
public:
	TestMediaNode();
	virtual ~TestMediaNode();
protected:
	virtual void initNodes();
private:
	void testMedia();
private:
};


