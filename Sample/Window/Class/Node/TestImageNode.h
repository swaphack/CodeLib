#pragma once

#include "TestFuncNode.h"

class TestImageNode : public TestFuncNode
{
public:
	TestImageNode();
	virtual ~TestImageNode();
protected:
	virtual void testFunc();
private:
	void testImage();

	void testDifferentImages();

	void testImages();

	void testMoveImage();

	void testPixelImage();
private:
	void onTouchBegin(sys::Object* object, float x, float y);
	void onTouchMove(sys::Object* object, float x, float y);
	void onTouchEnd(sys::Object* object, float x, float y);
	void onKeyBoard(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);


	void onTouchImage(sys::Object* object, float x, float y);
};