#include "CtrlWidget.h"

using namespace render;
render::CtrlWidget::CtrlWidget()
{

}

render::CtrlWidget::~CtrlWidget()
{

}

bool render::CtrlWidget::init()
{
	if (!ColorNode::init())
	{
		return false;
	}

	return true; 
}

