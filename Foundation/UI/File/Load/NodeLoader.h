#pragma once

#include "macros.h"

using namespace render;

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
	protected:
		// ui节点
		Widget* _node;
	private:
		INIT_LOADER_WIDGET(Widget);
	};
}