#pragma once

#include "macros.h"
#include "Parse/import.h"
#include "Load/import.h"

namespace ui
{
	class WidgetParser;

	// ui加载
	class UIProxy
	{
	public:
		UIProxy();
		virtual ~UIProxy();
	public:
		static UIProxy* getInstance();
		/**
		*	加载ui配置文件
		*/
		Widget* loadFile(const char* filepath);
		/**
		*	注册节点解析
		*/
		void registerNodeParser(const char* name, WidgetParser* parser);
		/**
		*	注销节点解析
		*/
		void unregisterNodeParser(const char* name);
		/**
		*	移除所有节点解析
		*/
		void removeAllNodeParsers();
	private:
		// 加载节点
		Widget* loadWidget(tinyxml2::XMLElement* pXmlNode);

		typedef std::map<std::string, WidgetParser*> NodeParsers;
		// 节点解析集合
		NodeParsers _nodeParsers;
	}; 

	#define G_UIPROXY sys::Instance<UIProxy>::getInstance()
}