#pragma once

#include "NodeLoader.h"

namespace ui
{
	class Layout;
	// 布局
	class LayoutLoader : public NodeLoader
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
		INIT_LOADER_WIDGET(Layout, render::Node, ELEMENT_NAME_LAYOUT);
	};

	/*
	class HorizontalLayout;
	// 水平布局
	class HLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(HorizontalLayout, ELEMENT_NAME_HLAYOUT);
	};

	class VerticalLayout;
	// 水平布局
	class VLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(VerticalLayout, ELEMENT_NAME_VLAYOUT);
	};
	*/
}