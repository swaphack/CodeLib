#include "CtrlMask.h"

using namespace ui;
using namespace render;

ui::CtrlMask::CtrlMask()
{
	this->setMeshVisible(true);
}

ui::CtrlMask::~CtrlMask()
{
}

bool ui::CtrlMask::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	return true;
}
