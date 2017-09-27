#pragma once

#include "WidgetProperty.h"
#include "text.h"

namespace ui
{
	// 节点解析器
	class IElement
	{
	public:
		IElement();
		virtual ~IElement();
	public:
		// 加载节点
		bool load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 保存节点
		bool save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 解析节点的名称
		virtual const char* getName() = 0;
	protected:
		// 属性
		WidgetProperty* getNodeProperty();
		// 解析属性
		virtual void parseAttributes() = 0;
		// 保存属性
		virtual void saveAttributes() = 0;
	private:
		// 节点属性
		WidgetProperty* _nodeProperty;
	};
}