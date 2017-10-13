#pragma once

#include "define.h"

namespace ui
{
	// 布局节点
	class NodeLoader : public IElement
	{
	public:
		NodeLoader();
		virtual ~NodeLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, Widget, ELEMENT_NAME_LAYOUT);
	};
}