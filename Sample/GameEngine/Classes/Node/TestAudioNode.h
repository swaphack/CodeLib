#pragma once

#include "TestFuncNode.h"

class TestAudioNode : public TestFuncNode
{
public:
	TestAudioNode();
	virtual ~TestAudioNode();
protected:
	virtual void testFunc();
private:
	void testAudio();
	void testAudio3D();
private:
	void onKeyBoardListener(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
};