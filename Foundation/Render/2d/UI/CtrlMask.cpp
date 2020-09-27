#include "CtrlMask.h"

render::CtrlMask::CtrlMask()
{
	this->setMeshVisible(true);
}

render::CtrlMask::~CtrlMask()
{
}

bool render::CtrlMask::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	return true;
}
