#pragma once

#include "WidgetLoader.h"

using namespace render;

namespace ui
{
	class TextLoader : public WidgetLoader
	{
	public:
		TextLoader();
		virtual ~TextLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlText, ELEMENT_NAME_TEXT);
	};
}