#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// ÎÄ±¾
	class TextAtlasLoader : public WidgetLoader
	{
	public:
		TextAtlasLoader();
		virtual ~TextAtlasLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlTextAtlas, ELEMENT_NAME_TEXT_ATLAS);
	};
}