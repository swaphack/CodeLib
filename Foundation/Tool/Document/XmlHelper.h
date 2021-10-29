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
		*	xml文档
		*/
		tinyxml2::XMLDocument* getDocument();
		/**
		*	根节点
		*/
		tinyxml2::XMLElement* getRoot();
	public:
		/**
		*	加载xml文件
		*/
		bool loadFile(const std::string& filepath);
		/**
		*	保存xml文件
		*/
		void saveTo(const std::string& filepath);
	public:
		/**
		*	获取根节点的属性
		*/
		void getRootAttributes(std::map<std::string, std::string>& value);
		/**
		*	设置根节点的属性
		*/
		void setRootAttributes(const std::map<std::string, std::string>& value);
	public:
		/**
		*	参数作为属性追加到节点
		*/
		void appendElementWithAttributes(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	参数作为子节点追加到节点
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::map<std::string, std::string>& value);
		/**
		*	参数作为子节点追加到节点（有序）
		*/
		void appendElementWithChildren(const std::string& nodeName, const std::vector<std::pair<std::string, std::string>>& value);
	public:
		/**
		*	获取节点
		*	比如 "a.b.c"
		*	<a><b><c></c></b></a>
		*/
		tinyxml2::XMLElement* getElement(const std::string& nodePath, const std::string& spot = ".");
		/**
		*	获取节点的属性值
		*/
		std::string getAttribute(const std::string& nodepath, const std::string& name);
		/**
		*	从根节点的子节点开始遍历
		*/
		void foreach(const std::function<void(tinyxml2::XMLElement*)>& func);
	private:
		// xml文档
		tinyxml2::XMLDocument* m_pDocument = nullptr;
	};
}