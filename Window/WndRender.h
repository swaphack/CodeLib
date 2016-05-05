#pragma once

#include "render.h"

class WndRender : public render::RenderApplication
{
public:
	WndRender();
	~WndRender();
public:
	void test();
	void testImage();
	void testClock();
	void testModel();
	void testText();
	void testMask();
	void testMedia();
	void testFog();
	void testAnimation();
	void testParticle();
};