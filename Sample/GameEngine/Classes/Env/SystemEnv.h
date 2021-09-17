#pragma once

#include "../Node/TestNode.h"

class SystemEnv : public TestNode
{
public:
	SystemEnv();
	~SystemEnv();
protected:
	virtual void initNodes();
private:
	void addFPS();

	void addCoordinate();

	void updateCamera();

	void addOperateToDesignCamera();
private:
	int _viewType = 0;

	float _spaceSpeed = 0.0f;
	float _mouseScroll = 0.0f;

	sys::ScrollEvent _scrollEvt = sys::ScrollEvent::NONE;
};
