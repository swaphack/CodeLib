#pragma once

#include "define.h"

namespace ui
{
	// UI节点
	class NodeLoader : public WidgetParser
	{ 
	public:
		NodeLoader();
		virtual ~NodeLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(Widget, ELEMENT_NAME_WIDGET);
	};
}