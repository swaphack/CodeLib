#pragma once


#include "CtrlListView.h"

namespace ui
{
	class CtrlTableView : public CtrlListView
	{
	public:
		CtrlTableView();
		virtual ~CtrlTableView();
	public:
		virtual bool init();

	};
}