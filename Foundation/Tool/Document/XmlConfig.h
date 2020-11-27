#pragma once

#include "tinyxml2.h"
#include <string>

namespace tool
{
	// xml 辅助工具
	class XmlHelper
	{
	public:
		XmlHelper();
		~XmlHelper();
	public:
		/// <summary>
		/// 加载xml文件
		/// </summary>
		/// <param name="filepath"></param>
		/// <returns></returns>
		bool loadFile(const std::string& filepath);
		/// <summary>
		/// 获取节点
		/// 比如 "a.b.c"
		/// </summary>
		/// <param name="nodePath"></param>
		/// <returns></returns>
		tinyxml2::XMLElement* getElement(const std::string& nodePath);
		/// <summary>
		/// 获取节点的属性值
		/// </summary>
		/// <param name="nodepath"></param>
		/// <param name="name"></param>
		/// <returns></returns>
		std::string getAttribute(const std::string& nodepath, const std::string& name);
	private:
		tinyxml2::XMLDocument* m_pDocument = nullptr;
	};
}