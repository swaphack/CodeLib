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
	void testMoveImage();
	void testClock();
	void testCubeModel();
	void testMultiFaceCube();
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

	void testModel();
	void testClipPlane();
	void testScissor();

	void testScrollView();

	void testUI();

	void testDrawNode();

	void testConcurrent();

	void testAudio();
	void testAudio3D();
	void testLayout();

	void test3ds();
	void testObj();
	void testFbx();

	void testShaderProgram();

	void testMatrix();

	void testHttpDownload();
protected:
	void onTouchBegin(sys::Object* object, float x, float y);
	void onTouchMove(sys::Object* object, float x, float y);
	void onTouchEnd(sys::Object* object, float x, float y);
	void onKeyBoard(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);

	void onTouchImage(sys::Object* object, float x, float y);
	void onKeyBoardCamera(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
	void onKeyBoardRole(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
	void onKeyBoardListener(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
private:
	sys::ConcurrentFile* _concurFile = nullptr;
	sys::HttpDownload* _httpDownload = nullptr;
};