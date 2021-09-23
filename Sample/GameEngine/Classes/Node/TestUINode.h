#pragma once

#include "../Env/TestNode.h"

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

	void testListView();

	void testMask();

	void testStencil();

	void testImage();

	void testButton();

	void testWidget();

	void testText();
private:

	void onKeyBoardRole(render::Node* node, sys::BoardKey key, sys::ButtonStatus type);
};