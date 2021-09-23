#pragma once

#include "../Env/TestNode.h"
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

	void addStar();

	void addEarth();

	
	void addGround();

	void testCubeModel();

	void testShadow();
};