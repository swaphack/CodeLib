#pragma once

#include "render.h"
#include "ui.h"
#include "algorithm.h"
#include "render.h"

class WndRender : public render::RenderApplication
{
public:
	WndRender();
	virtual ~WndRender();
public:
	virtual void show();
protected:
	void testProgram();
};