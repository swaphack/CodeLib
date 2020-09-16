#pragma once

#include "TestNode.h"

class TestAlgNode : public TestNode
{
public:
	TestAlgNode();
	virtual ~TestAlgNode();
protected:
	virtual void initNodes();
private:
	void testRayMapFindPath();

	void testMeshMapFindPath();
};