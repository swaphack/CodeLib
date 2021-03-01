#pragma once

#include "render.h"
#include "Layout/macros.h"
#include "Layout/LayoutItem.h"
namespace ui
{
	class IElement;
	class CtrlWidget;

	// ui加载
	class UIProxy
	{
	private:
		UIProxy();
		virtual ~UIProxy();
	public:
		static UIProxy* getInstance();
		/**
		*	加载ui配置文件
		*/
		CtrlWidget* loadFile(const std::string& filepath, const math::Size& size);
		/**
		*	保存ui配置文件
		*/
		bool saveFile(CtrlWidget* CtrlWidget, const std::string& filepath, const math::Size& designSize);
		/**
		*	注册节点解析
		*/
		void registerElementParser(const std::string& name, IElement* parser);
		/**
		*	注销节点解析
		*/
		void unregisterElementParser(const std::string& name);
		/**
		*	移除所有节点解析
		*/
		void removeAllElementParsers();
		/**
		*	设计大小
		*/
		const math::Size& getDesignSize() const;
		/**
		*	获取布局方向
		*/
		LayoutDirection getDesignDirection() const;
	public:
		/**
		*	默认字体
		*/
		const std::string& getFontPath();
		/**
		*	设置默认字体
		*/
		void setFontPath(const std::string& fontPath);
	public:
		/**
		*	获取布局
		*/ 
		static ui::LayoutItem* getLayoutItem(ui::CtrlWidget* item);

		/**
		*	获取控件名称
		*/  
		static std::string getLayoutItemName(ui::CtrlWidget* item);

		/**
		*	获取子节点
		*/ 
		static render::Node* getChildByIndex(render::Node* node, int index);
		/**
		*	获取可视子节点
		*/
		static bool getVisibleChildren(const render::Node* node, std::vector<render::Node*>& children);
	protected:
		/**
		*	初始化
		*/
		void init();
		/**
		*	获取节点
		*/
		IElement* getElement(const std::string& name);
	protected:
		//////////////////////////////////////////////////////////////////////////
		// 加载单一节点
		CtrlWidget* initWidget(tinyxml2::XMLElement* xmlNode);
		// 加载布局
		bool loadWidget(CtrlWidget* pCtrlWidget, tinyxml2::XMLElement* xmlNode);
		// 加载根元素
		CtrlWidget* loadRoot(tinyxml2::XMLElement* xmlNode, const math::Size& size);
		//////////////////////////////////////////////////////////////////////////
		// 保存布局
		bool saveWidget(CtrlWidget* item, tinyxml2::XMLElement* xmlNode);
		// 保存根元素
		bool saveRoot(CtrlWidget* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// 节点解析集合
		ElementParsers _elementParsers;
		// 设计大小
		math::Size _designSize;
		// 布局方向
		LayoutDirection _designDirection;
		// 默认字体
		std::string _defaultFontPath;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}