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

	void testMoveImage();

	void testPixelImage();

	void testPointSprite();
private:
	void onTouchBegin(Node* node, float x, float y, bool include);
	void onTouchMove(Node* node, float x, float y, bool include);
	void onTouchEnd(Node* node, float x, float y, bool include);
	void onKeyBoard(Node* node, sys::BoardKey key, sys::ButtonStatus type);


	void onTouchImage(Node* node, float x, float y, bool include);
};