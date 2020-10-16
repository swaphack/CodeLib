#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// °´Å¥
	class EditLabelLoader : public WidgetLoader
	{
	public:
		EditLabelLoader();
		virtual ~EditLabelLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, render::CtrlEditLabel, ELEMENT_NAME_EDITLABEL);
	};
}