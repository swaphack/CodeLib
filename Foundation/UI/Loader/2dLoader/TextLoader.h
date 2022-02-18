#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// нд╠╬
	class TextLoader : public WidgetLoader
	{
	public:
		TextLoader();
		virtual ~TextLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(CtrlText, ELEMENT_NAME_TEXT);
	};
}