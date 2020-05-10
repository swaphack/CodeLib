#pragma once

#include "render.h"

class TestFuncNode : public render::Node
{
public:
	TestFuncNode();
	virtual ~TestFuncNode();
public:
	virtual bool init();
protected:
	virtual void testFunc();
private:
};


