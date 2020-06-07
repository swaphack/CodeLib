#pragma once

#include "../ElementWidget/import.h"
#include "render.h"

namespace ui
{
	// 布局节点
	class WidgetLoader : public IElement
	{
	public:
		WidgetLoader();
		virtual ~WidgetLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, render::CtrlWidget, ELEMENT_NAME_WIDGET);
	};
}