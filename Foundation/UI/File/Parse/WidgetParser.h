#pragma once

#include "helper.h"
#include "IElement.h"

namespace ui
{
	// 节点解析器
	class WidgetParser : public IElement
	{
	public:
		WidgetParser();
		virtual ~WidgetParser();
	protected:
		// 解析属性
		virtual void parseAttributes() = 0;
		// 保存属性
		virtual void saveAttributes() = 0;
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