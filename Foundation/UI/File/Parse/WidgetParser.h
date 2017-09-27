#pragma once

#include "IElement.h"
#include "macros.h"

namespace ui
{
	// 节点解析器
	class WidgetParser : public IElement
	{
	public:
		WidgetParser();
		virtual ~WidgetParser();
	public:
		// 设置ui节点
		void setWidget(Widget* widget);
		// 获取ui节点
		virtual Widget* getWidget() = 0;

		// 解析节点的名称
		virtual const char* getName() = 0;
	protected:
		// 解析属性
		virtual void parseAttributes() = 0;
		// 保存属性
		virtual void saveAttributes() = 0;
	protected:
		// ui节点
		Widget* _node;
	};
}