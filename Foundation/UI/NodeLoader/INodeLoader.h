#pragma once

#include "macros.h"
#include "NodeProperty.h"

namespace ui
{
	// 节点加载解析接口
	class INodeLoader
	{
	public:
		INodeLoader();
		virtual ~INodeLoader();
	public:
		// 加载节点
		render::Node* load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 保存节点数据
		void save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// 获取节点属性
		NodeProperty* getAttributeLoader();
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
		// 获取ui节点
		virtual render::Node* getNode() = 0;
		// 注册解析
		virtual void registerNodeParser() = 0;
	protected:
		// ui节点
		render::Node* _node;
		// 节点属性
		NodeProperty* _elementLoader;
	};
}