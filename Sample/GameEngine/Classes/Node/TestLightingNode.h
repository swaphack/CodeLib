#pragma once

#include "TestNode.h"
/**
*	π‚’’
*/
class TestLightingNode : public TestNode
{
public:
	TestLightingNode();
	virtual ~TestLightingNode();
protected:
	virtual void initNodes();
private:
	void addSun();

	void addEarth();


	void testCubeModel();
};