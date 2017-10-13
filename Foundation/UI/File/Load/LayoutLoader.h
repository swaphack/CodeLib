#pragma once

#include "NodeLoader.h"

namespace ui
{
	class Layout;
	// ����
	class LayoutLoader : public NodeLoader
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
		INIT_LOADER_WIDGET(Layout, render::Node, ELEMENT_NAME_LAYOUT);
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