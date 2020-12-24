#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// ��ť
	class ButtonLoader : public WidgetLoader
	{
	public:
		ButtonLoader();
		virtual ~ButtonLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlButton, ELEMENT_NAME_BUTTON);
	};
}