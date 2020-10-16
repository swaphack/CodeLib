#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// °´Å¥
	class ButtonLoader : public WidgetLoader
	{
	public:
		ButtonLoader();
		virtual ~ButtonLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, render::CtrlButton, ELEMENT_NAME_BUTTON);
	};
}