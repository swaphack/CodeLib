#pragma once

#include "render.h"


class WndRender : public render::RenderApplication
{
public:
	WndRender();
	virtual ~WndRender();
public:
	virtual void show();
protected:
};