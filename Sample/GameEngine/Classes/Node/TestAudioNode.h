#pragma once

#include "TestNode.h"

class TestAudioNode : public TestNode
{
public:
	TestAudioNode();
	virtual ~TestAudioNode();
protected:
	virtual void initNodes();
private:
	void testAudio();
	void testAudio3D();
private:
	void onKeyBoardListener(render::Node* node, sys::BoardKey key, sys::ButtonStatus type);
};