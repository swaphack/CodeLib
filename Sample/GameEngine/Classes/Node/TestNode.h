#pragma once

#include "render.h"

class TestNode : public render::Node
{
public:
	TestNode();
	virtual ~TestNode();
public:
	virtual bool init();
protected:
	virtual void initNodes();
private:
};


