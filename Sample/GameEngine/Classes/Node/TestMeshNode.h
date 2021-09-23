#pragma once

#include "../Env/TestNode.h"

// Íø¸ñ
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