#pragma once

#include "TestNode.h"

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

	void init3DSkyBox();
	void init2DSkyBox();

	void addGrid();
private:
	int _viewType = 0;

	float _spaceSpeed = 0.0f;
	float _mouseScroll = 0.0f;

	sys::ScrollEvent _scrollEvt = sys::ScrollEvent::NONE;
};
