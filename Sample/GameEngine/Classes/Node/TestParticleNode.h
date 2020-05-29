#pragma once

#include "TestFuncNode.h"

class TestParticleNode : public TestFuncNode
{
public:
	TestParticleNode();
	virtual ~TestParticleNode();
protected:
	virtual void testFunc();
private:
	void testParticle();

	render::Node* createCubeModel();
};