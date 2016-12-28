#pragma once

#include "LayoutItemLoader.h"

namespace ui
{
	// 布局节点
	class LayoutLoader : public LayoutItemLoader
	{
	public:
		LayoutLoader();
		virtual ~LayoutLoader();
	protected:
		// 解析属性
		virtual void parseAttributes();
		// 保存属性
		virtual void saveAttributes();
	private:
		INIT_LOADER_WIDGET(Layout, Layout);
	};
}