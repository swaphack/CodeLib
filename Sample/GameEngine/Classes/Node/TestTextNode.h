#pragma once

#include "../Env/TestNode.h"

class TestTextNode : public TestNode
{
public:
	TestTextNode();
	virtual ~TestTextNode();
protected:
	virtual void initNodes();
private:
	void testTimeText();
	void testChineseText();
private:
};


