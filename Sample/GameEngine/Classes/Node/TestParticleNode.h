#pragma once

#include "TestNode.h"

class TestParticleNode : public TestNode
{
public:
	TestParticleNode();
	virtual ~TestParticleNode();
protected:
	virtual void initNodes();
private:
	void testParticle();

	render::Node* createCubeModel();
};