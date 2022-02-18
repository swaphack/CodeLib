#pragma once

#include "WidgetLoader.h"

namespace ui
{
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
		INIT_LOADER_WIDGET(CtrlLayout, ELEMENT_NAME_LAYOUT);
	};
}