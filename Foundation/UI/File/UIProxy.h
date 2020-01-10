#pragma once

#include "Parse/import.h"
#include "Load/import.h"
#include "text.h"
#include "ui_common.h"

namespace ui
{
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
		bool saveFile(Layout* layout, const char* filepath, const math::Size& designSize);
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
		/**
		*	设计大小
		*/
		const math::Size& getDesignSize();
		/**
		*	获取布局方向
		*/
		LayoutDirection getDesignDirection();
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
		LayoutItem* initLoadItem(tinyxml2::XMLElement* xmlNode);
		// 加载布局
		bool loadLayout(Layout* loader, tinyxml2::XMLElement* xmlNode);
		// 加载根元素
		Layout* loadRoot(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// 保存节点
		bool saveWidget(Widget* widget, tinyxml2::XMLElement* xmlNode);
		// 保存布局
		bool saveLayoutItem(LayoutItem* item, tinyxml2::XMLElement* xmlNode);
		// 保存根元素
		bool saveRoot(Layout* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// 节点解析集合
		ElementParsers _elementParsers;
		// 设计大小
		math::Size _designSize;
		// 布局方向
		LayoutDirection _designDirection;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}