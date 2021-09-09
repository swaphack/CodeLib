#pragma once

#include "render.h"

class TestMainScene : public render::Scene
{
public:
	TestMainScene();
	virtual ~TestMainScene();
public:
	virtual bool init();
protected:
	void initNodes();
	void initEnv();
};

