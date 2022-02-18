#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// 布局
	class LayoutLoader : public WidgetLoader
	{
	public:
		LayoutLoader();
		virtual ~LayoutLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(CtrlLayout, ELEMENT_NAME_LAYOUT);
	};
}