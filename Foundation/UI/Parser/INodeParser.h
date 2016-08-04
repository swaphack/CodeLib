#pragma once

#include "macros.h"
#include "NodeProperty.h"
#include "helper.h"
#include "INodeLoad.h"
#include "INodeSave.h"

namespace ui
{
	// 节点解析器
	class INodeParser : 
		public INodeLoad, 
		public INodeSave
	{
	public:
		INodeParser();
		virtual ~INodeParser();
	public:
		// 加载节点
		virtual render::Node* load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 保存节点
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// 属性
		NodeProperty* getNodeProperty();
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
		// 获取ui节点
		virtual render::Node* getNode() = 0;
		// 注册解析
		virtual void registerNodeParser() = 0;
	private:
		// 节点属性
		NodeProperty* _nodeProperty;
	};
}