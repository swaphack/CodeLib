#pragma once

#include "ScrollViewLoader.h"

namespace ui
{
	// 列表
	class TableViewLoader : public ScrollViewLoader
	{
	public:
		TableViewLoader();
		virtual ~TableViewLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlTableView, ELEMENT_NAME_TABLEVIEW);
	};
}