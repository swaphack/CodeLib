#pragma once

#include "WidgetLoader.h"
#include "render.h"

namespace ui
{
	class Layout;
	// ����
	class LayoutLoader : public WidgetLoader
	{
	public:
		LayoutLoader();
		virtual ~LayoutLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(Layout, render::CtrlLayout, ELEMENT_NAME_LAYOUT);
	};

	/*
	class HorizontalLayout;
	// ˮƽ����
	class HLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(HorizontalLayout, ELEMENT_NAME_HLAYOUT);
	};

	class VerticalLayout;
	// ˮƽ����
	class VLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(VerticalLayout, ELEMENT_NAME_VLAYOUT);
	};
	*/
}