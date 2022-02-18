#pragma once

#include "WidgetProperty.h"
#include "Layout/LayoutItem.h"
#include "UI/CtrlWidget.h"
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
		bool load(tinyxml2::XMLElement* pXmlNode, const math::Size& parentSize, bool clean = true);
		// 保存节点
		bool save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 解析节点的名称
		virtual std::string getName() = 0;
		// 设置ui节点
		void setWidget(CtrlWidget* node);
		// 获取控件
		CtrlWidget* getWidget();
		// 获取布局
		LayoutItem* getLayoutItem();
		/**
		*	默认字体
		*/
		const std::string& getFontPath() const;
		/**
		*	设置默认字体
		*/
		void setFontPath(const std::string& fontPath);
		/**
		*	默认字体Image
		*/
		const std::string& getFontImagePath() const;
		/**
		*	设置默认字体Image
		*/
		void setFontImagePath(const std::string& fontImagePath);
		/**
		*	默认字体
		*/
		const math::Size& getParentSize() const;
		/**
		*	设置默认字体
		*/
		void setParentSize(const math::Size& size);
	protected:
		// 属性
		WidgetProperty* getNodeProperty();
		// 解析属性
		virtual void parseAttributes() = 0;
		// 保存属性
		virtual void saveAttributes() = 0;
		// 初始化控件
		virtual void initWidget() = 0;
	private:
		// 节点属性
		WidgetProperty* _nodeProperty;
	protected:
		// ui控件
		CtrlWidget* _node = nullptr;
		// 默认字体
		std::string _defaultFontPath;
		// 默认字体图片
		std::string _defaultFontImagePath;
		// 父节点大小
		math::Size _parentSize;
	};
}