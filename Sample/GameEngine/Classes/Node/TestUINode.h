#pragma once

#include "TestFuncNode.h"

class TestUINode : public TestFuncNode
{
public:
	TestUINode();
	virtual ~TestUINode();
protected:
	virtual void testFunc();
private:
	void testEditBox();

	void testSequenceFrame();

	void testScissor();

	void testScrollView();

	void testMask();

	void testStencil();

	void testImage();
private:

	void onKeyBoardRole(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
};