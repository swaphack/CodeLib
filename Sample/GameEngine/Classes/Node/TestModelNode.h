#pragma once

#include "TestFuncNode.h"

class TestModelNode : public TestFuncNode
{
public:
	TestModelNode();
	virtual ~TestModelNode();
protected:
	virtual void testFunc();
private:
	void testCubeModel();
	void testSphereModel();

	void addLight();

	void test3ds();
	void testObj();
	void testFbx();

	void testMultiFaceCube();

	void testFog();
	void testCamera();

	void testClipPlane();
private:
	void onKeyBoardCamera(render::Node* node, sys::BoardKey key, sys::ButtonStatus type);
};