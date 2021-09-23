#pragma once

#include "TestNode.h"

class TerrianNode : public TestNode
{
public:
	TerrianNode();
	~TerrianNode();
protected:
	virtual void initNodes();

	void addTerrian();
};