#pragma once

#include "macros.h"
#include "INodeLoader.h"

namespace ui
{
	// ui加载
	class UIProxy
	{
	public:
		UIProxy();
		virtual ~UIProxy();
	public:
		// 加载ui配置文件
		render::Node* loadFile(const char* filepath);
		// 注册节点解析
		void registerNodeParser(const char* name, INodeLoader* parser);
	private:
		// 加载节点
		render::Node* loadNode(tinyxml2::XMLElement* pXmlNode);

		std::map<std::string, INodeLoader*> _nodeParsers;
	}; 

	#define G_UIPROXY sys::Instance<UIProxy>::getInstance()
}