#pragma once

#include "define.h"

namespace ui
{
	// 布局节点
	class LayoutItemLoader : public LayoutItemParser
	{
	public:
		LayoutItemLoader();
		virtual ~LayoutItemLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_LAYOUTITEM(LayoutItem, ELEMENT_NAME_LAYOUTITEM);
	};
}