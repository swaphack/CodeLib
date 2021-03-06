#pragma once

#include "TestNode.h"

class TestModelNode : public TestNode
{
public:
	TestModelNode();
	virtual ~TestModelNode();
protected:
	virtual void initNodes();
private:
	void testCubeModel();
	void testSphereModel();

	void addLight();

	void test3ds();
	void testObj();
	void testFbx();

	void testMultiFaceCube();

	void testCubeMap();

	void testFog();
	void testCamera();

	void testClipPlane();
private:
	void onKeyBoardCamera(render::Node* node, sys::BoardKey key, sys::ButtonStatus type);
};