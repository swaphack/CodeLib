#pragma once

#include "render.h"

class WndRender : public render::RenderApplication
{
public:
	WndRender();
	virtual ~WndRender();
public:
	virtual void show();
	void testMoveImage();
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
	void testPixelImage();
	void testSequenceFrame();
protected:
	void onTouchBegin(sys::Object* object, float x, float y);
	void onTouchMove(sys::Object* object, float x, float y);
	void onTouchEnd(sys::Object* object, float x, float y);
	void onKeyBoard(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);

	void onTouchImage(sys::Object* object, float x, float y);
	void onKeyBoardCamera(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
};