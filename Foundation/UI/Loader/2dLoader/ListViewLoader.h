#pragma once

#include "ScrollViewLoader.h"

namespace ui
{
	// 列表
	class ListViewLoader : public ScrollViewLoader
	{
	public:
		ListViewLoader();
		virtual ~ListViewLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlListView, ELEMENT_NAME_LISTVIEW);
	};
}