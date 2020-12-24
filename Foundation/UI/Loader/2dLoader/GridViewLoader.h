#pragma once

#include "ListViewLoader.h"

namespace ui
{
	// 列表
	class GridViewLoader : public ListViewLoader
	{
	public:
		GridViewLoader();
		virtual ~GridViewLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlGridView, ELEMENT_NAME_GRIDVIEW);
	};
}