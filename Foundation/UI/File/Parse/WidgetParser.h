#pragma once

#include "macros.h"
#include "helper.h"
#include "WidgetProperty.h"
#include "IXmlLoader.h"
#include "IXmlSaver.h"

namespace ui
{
	// 节点解析器
	class WidgetParser : 
		public IXmlLoader, 
		public IXmlSaver
	{
	public:
		WidgetParser();
		virtual ~WidgetParser();
	public:
		// 加载节点
		virtual Widget* load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// 保存节点
		virtual void save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
	protected:
		// 属性
		WidgetProperty* getNodeProperty();
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
		// 获取ui节点
		virtual Widget* getWidget() = 0;
		// 注册解析
		virtual void registerNodeParser() = 0;
	private:
		// 节点属性
		WidgetProperty* _nodeProperty;
		// 属性发生改变时的处理
		std::map<std::string, std::function<void>(std::string, std::string) > _onChangedHandler;
	};
}