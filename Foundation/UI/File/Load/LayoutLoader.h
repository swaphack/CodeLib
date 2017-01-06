#pragma once

#include "LayoutItemLoader.h"

namespace ui
{


#define ELEMENT_NAME_LAYOUT			"Layout"
#define ELEMENT_NAME_HLAYOUT		"HLayout"
#define ELEMENT_NAME_VLAYOUT		"VLayout"

	// ����
	class LayoutLoader : public LayoutItemLoader
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
		INIT_LOADER_LAYOUTITEM(Layout, ELEMENT_NAME_LAYOUT);
	};

	// ˮƽ����
	class HLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(HorizontalLayout, ELEMENT_NAME_HLAYOUT);
	};

	// ˮƽ����
	class VLayoutLoader : public LayoutLoader
	{
	public:
		INIT_LOADER_LAYOUTITEM(VerticalLayout, ELEMENT_NAME_VLAYOUT);
	};
}