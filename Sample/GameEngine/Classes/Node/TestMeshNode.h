#pragma once

#include "TestNode.h"

// ����
class TestMeshNode : public TestNode
{
public:
	TestMeshNode();
	virtual ~TestMeshNode();
protected:
	virtual void initNodes();
protected:
	void testMesh();
	void testBrokenMesh();
private:
};