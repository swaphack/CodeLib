#pragma once

#include "../Env/TestNode.h"

class TestParticleNode : public TestNode
{
public:
	TestParticleNode();
	virtual ~TestParticleNode();
protected:
	virtual void initNodes();
private:
	void testCollideParticle();

	void testXFBParticle();

	render::Node* createCubeModel();
};