#pragma once

#include "macros.h"
#include "Parse/import.h"
#include "Load/import.h"

namespace ui
{
	/**
	*	元素类型
	*/
	enum ElementType
	{
		/**
		*	未定义
		*/
		EET_NONE,
		/**
		*	控件
		*/
		EET_WIDGET,
		/**
		*	布局节点
		*/
		EET_LAYOUTITEM,
		/**
		*	布局
		*/
		EET_LAYOUT,
	};

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
		Layout* loadFile(const char* filepath);
		/**
		*	保存ui配置文件
		*/
		bool saveFile(Layout* layout, const char* filepath);
		/**
		*	注册节点解析
		*/
		void registerElementParser(const char* name, IElement* parser);
		/**
		*	注销节点解析
		*/
		void unregisterElementParser(const char* name);
		/**
		*	移除所有节点解析
		*/
		void removeAllElementParsers();
	protected:
		/**
		*	初始化
		*/
		void init();
		/**
		*	获取节点
		*/
		IElement* getElement(const char* name);
	protected:
		//////////////////////////////////////////////////////////////////////////
		// 加载单一节点
		IElement* loadSingleElement(tinyxml2::XMLElement* xmlNode, ElementType& type);
		// 加载布局节点
		bool loadLayoutItem(LayoutItemLoader* loader, tinyxml2::XMLElement* xmlNode);
		// 加载布局
		bool loadLayout(LayoutLoader* loader, tinyxml2::XMLElement* xmlNode);
		// 加载根元素
		IElement* loadRoot(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// 保存节点
		bool saveWidget(Widget* widget, tinyxml2::XMLElement* xmlNode);
		// 保存布局项
		bool saveLayoutItem(LayoutItem* layoutItem, tinyxml2::XMLElement* xmlNode);
		// 保存布局
		bool saveLayout(Layout* layout, tinyxml2::XMLElement* xmlNode);
		// 保存根元素
		bool saveRoot(Layout* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// 节点解析集合
		ElementParsers _elementParsers;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}