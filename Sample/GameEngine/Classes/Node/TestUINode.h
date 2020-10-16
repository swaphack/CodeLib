#pragma once

#include "TestNode.h"

class TestUINode : public TestNode
{
public:
	TestUINode();
	virtual ~TestUINode();
protected:
	virtual void initNodes();
private:
	void testEditBox();

	void testSequenceFrame();

	void testScissor();

	void testScrollView();

	void testMask();

	void testStencil();

	void testImage();

	void testButton();
private:

	void onKeyBoardRole(render::Node* node, sys::BoardKey key, sys::ButtonStatus type);
};