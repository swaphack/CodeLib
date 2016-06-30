#pragma once

#include "render.h"

class WndRender : public render::RenderApplication
{
public:
	WndRender();
	virtual ~WndRender();
public:
	virtual void show();
	void testImage();
	void testClock();
	void testCubeModel();
	void testSphereModel();
	void testText();
	void testMask();
	void testMedia();
	void testFog();
	void testAnimation();
	void testParticle(); 
	void testStencil();
	void testCamera();
	void testEditBox();
	void testImages();
	void testString();
	void addLight();
};