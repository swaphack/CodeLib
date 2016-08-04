#pragma once


#include "macros.h"

namespace ui
{
	// 节点加载解析接口
	class INodeSave
	{
	public:
		virtual ~INodeSave() = 0;
	public:
		// 保存节点
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true) = 0;
	protected:
		// 保存属性
		virtual void saveAttributes() = 0;
	};
}