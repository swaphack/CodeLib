#pragma once

#include "TestNode.h"

class TestImageNode : public TestNode
{
public:
	TestImageNode();
	virtual ~TestImageNode();
protected:
	virtual void initNodes();
private:
	void testImage();

	void testGrayImage();

	void testDifferentImages();

	void testMoveImage();

	void testPixelImage();

	void testPointSprite();

	void testImages();

	void testScale9Image();
private:
	void onTouchBegin(Node* node, const math::Vector2& touchPoint);
	void onTouchMove(Node* node, const math::Vector2& touchPoin);
	void onTouchEnd(Node* node, const math::Vector2& touchPoint);
	void onKeyBoard(Node* node, sys::BoardKey key, sys::ButtonStatus type);


	void onTouchImage(Node* node, const math::Vector2& touchPoint);
};