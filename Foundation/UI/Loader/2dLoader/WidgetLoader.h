#pragma once

#include "Loader/ElementWidget/import.h"
#include "render.h"
#include "macros.h"
#include "UI/import.h"

namespace ui
{
	// 控件
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
		INIT_LOADER_WIDGET(CtrlWidget, ELEMENT_NAME_WIDGET);
	};
}