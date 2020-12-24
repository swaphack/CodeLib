#pragma once

#include "CtrlListView.h"

namespace ui
{
	// 网格列表
	class CtrlGridView : public CtrlListView
	{
	public:
		CtrlGridView();
		virtual ~CtrlGridView();
	public:
		virtual bool init();
	protected:
		// 初始化滑动项
		virtual void initItems();
	};
}
