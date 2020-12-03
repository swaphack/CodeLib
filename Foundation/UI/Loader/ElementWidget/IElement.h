#pragma once

#include "WidgetProperty.h"
#include "Layout/LayoutItem.h"
#include "Layout/Layout.h"
#include "system.h"
#include "render.h"

namespace ui
{
	// 节点解析器
	class IElement : public sys::Object
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
		virtual std::string getName() = 0;
		// 设置布局节点
		void setLayoutItem(LayoutItem* item);
		// 设置ui节点
		void setWidget(render::CtrlWidget* node);
		// 获取布局
		LayoutItem* getLayoutItem();
		// 获取控件
		render::CtrlWidget* getWidget();
		/**
		*	默认字体
		*/
		const std::string& getFontPath();
		/**
		*	设置默认字体
		*/
		void setFontPath(const std::string& fontPath);
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
		render::CtrlWidget* _node = nullptr;
		LayoutItem* _layoutItem = nullptr;
		// 默认字体
		std::string _defaultFontPath;
	};
}