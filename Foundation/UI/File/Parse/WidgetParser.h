#pragma once

#include "helper.h"
#include "IElement.h"

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