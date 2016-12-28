#pragma once

#include "macros.h"

namespace ui
{
	// 布局节点
	class LayoutItemLoader : public WidgetParser
	{
	public:
		LayoutItemLoader();
		virtual ~LayoutItemLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	};
}