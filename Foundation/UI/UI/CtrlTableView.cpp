#include "CtrlTableView.h"

ui::CtrlTableView::CtrlTableView()
{
}

ui::CtrlTableView::~CtrlTableView()
{
}

bool ui::CtrlTableView::init()
{
	if (!CtrlListView::init())
	{
		return false;
	}


	return true;
}
