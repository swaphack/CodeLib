#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// °´Å¥
	class EditTextLoader : public WidgetLoader
	{
	public:
		EditTextLoader();
		virtual ~EditTextLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlEditText, ELEMENT_NAME_EDITTEXT);
	};
}