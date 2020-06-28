#pragma once

#include "TestNode.h"

class TestEnvironmentNode : public TestNode
{
public:
	TestEnvironmentNode();
	virtual ~TestEnvironmentNode();
protected:
	virtual void initNodes();
protected:
	void init3DSkyBox();
	void init2DSkyBox();

	void testCamera();
private:
	int _viewType = 0;

	float _spaceSpeed = 0.0f;
	float _mouseScroll = 0.0f;

	sys::ScrollEvent _scrollEvt = sys::ScrollEvent::NONE;
};