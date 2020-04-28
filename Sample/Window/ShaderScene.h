#pragma once

#include "render.h"

class ShaderScene : public render::Scene
{
public:
	ShaderScene();
	virtual ~ShaderScene();
public:
	virtual bool init();
protected:
	void testColorShader();
private:
};