#pragma once

#include "WidgetProperty.h"
#include "text.h"
#include "macros.h"

namespace ui
{
	class LayoutItem;

	// 节点解析器
	class IElement
	{
	public:
		IElement();
		virtual ~IElement();
	public:
		// 加载节点
		bool load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 保存节点
		bool save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 解析节点的名称
		virtual const char* getName() = 0;
		// 设置布局节点
		void setLayoutItem(LayoutItem* item);
		// 设置ui节点
		void setWidget(Widget* node);
		// 获取布局
		LayoutItem* getLayoutItem();
		// 获取控件
		Widget* getWidget();
	protected:
		// 属性
		WidgetProperty* getNodeProperty();
		// 解析属性
		virtual void parseAttributes() = 0;
		// 保存属性
		virtual void saveAttributes() = 0;
		// 初始化布局
		virtual void initLayoutItem() = 0;
		// 初始化控件
		virtual void initWidget() = 0;
	private:
		// 节点属性
		WidgetProperty* _nodeProperty;
	protected:
		Widget* _node = nullptr;
		LayoutItem* _layoutItem = nullptr;
	};
}