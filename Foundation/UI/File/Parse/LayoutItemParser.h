#pragma once

#include "helper.h"
#include "IElement.h"

namespace ui
{
	// 布局解析器
	class LayoutItemParser : public IElement
	{
	public:
		LayoutItemParser();
		virtual ~LayoutItemParser();
	public:
		// 设置ui节点
		void setLayoutItem(LayoutItem* item);

		// 获取ui节点
		virtual LayoutItem* getLayoutItem() = 0;
	protected:
		// 解析属性
		virtual void parseAttributes() = 0;
		// 保存属性
		virtual void saveAttributes() = 0;
	protected:
		LayoutItem* m_pLayoutItem;
	};
}