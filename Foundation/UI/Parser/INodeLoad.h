#pragma once

#include "macros.h"

namespace ui
{	
	// 节点加载解析接口
	class INodeLoad
	{
	public:
		virtual ~INodeLoad() = 0;
	public:
		// 加载节点
		virtual render::Node* load(tinyxml2::XMLElement* pXmlNode, bool clean = true) = 0;
	protected:
		// 解析属性
		virtual void parseAttributes() = 0;
	};
}