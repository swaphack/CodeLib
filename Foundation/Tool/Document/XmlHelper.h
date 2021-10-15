#pragma once

#include "tinyxml2.h"
#include <string>
#include <map>
#include <vector>
#include <functional>

namespace tool
{
	// xml 辅助工具
	class XmlHelper
	{
	public:
		XmlHelper();
		~XmlHelper();
	public:
		/**
		*	加载xml文件
		*/
		bool loadFile(const std::string& filepath);
		/**
		*	获取节点
		*	比如 "a.b.c"
		*	<a><b><c></c></b></a>
		*/
		tinyxml2::XMLElement* getElement(const std::string& nodePath, const std::string& spot =".");
		/**
		*	获取节点的属性值
		*/
		std::string getAttribute(const std::string& nodepath, const std::string& name);
		/**
		*	从根节点开始遍历
		*/
		void foreach(const std::function<void(tinyxml2::XMLElement*)>& func);
	public:
		/**
		*	保存xml文件
		*/
		void saveTo(const std::string& filepath);
		/**
		*	追加元素
		*/
		void appendElementWithAttributes(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	保存xml文件
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	保存xml文件
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::vector<std::pair<std::string, std::string>>& value);
	private:
		tinyxml2::XMLDocument* m_pDocument = nullptr;
	};
}