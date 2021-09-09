#pragma once

#include "../Node/TestNode.h"

class SystemEnv : public TestNode
{
public:
	SystemEnv();
	~SystemEnv();
protected:
	virtual void initNodes();
private:
	void addFPS();

	void addCoordinate();

	void updateCamera();
};
