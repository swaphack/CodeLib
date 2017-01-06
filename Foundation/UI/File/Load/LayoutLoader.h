#pragma once

#include "LayoutItemLoader.h"

namespace ui
{


#define ELEMENT_NAME_LAYOUT			"Layout"
#define ELEMENT_NAME_HLAYOUT		"HLayout"
#define ELEMENT_NAME_VLAYOUT		"VLayout"

	// 布局
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
	public:
		INIT_LOADER_LAYOUTITEM(Layout, ELEMENT_NAME_LAYOUT);
	};

	// 水平布局
	class HLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(HorizontalLayout, ELEMENT_NAME_HLAYOUT);
	};

	// 水平布局
	class VLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(VerticalLayout, ELEMENT_NAME_VLAYOUT);
	};
}