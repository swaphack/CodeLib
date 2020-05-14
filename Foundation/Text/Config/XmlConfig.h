#pragma once

#include "tinyxml2.h"

namespace sys
{
	// xml 配置
	class XmlConfig
	{
	public:
		XmlConfig();
		~XmlConfig();
	public:
		// 加载xml文件
		bool loadFile(const char* filepath);
		// 获取节点
		tinyxml2::XMLElement* getElement(const char* nodePath);
		// 获取节点的属性值
		const char* getValue(const char* nodepath, const char* attributeName);
	private:
		tinyxml2::XMLDocument* m_pDocument;
	};
}