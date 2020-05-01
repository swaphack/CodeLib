#pragma once

#include "render.h"


class GLRenderApplication : public render::RenderApplication
{
public:
	GLRenderApplication();
	virtual ~GLRenderApplication();
public:
	virtual void show();
protected:
};