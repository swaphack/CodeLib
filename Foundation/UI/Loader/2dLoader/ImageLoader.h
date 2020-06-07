#pragma once

#include "WidgetLoader.h"

namespace ui
{
	class ImageLoader : public WidgetLoader
	{
	public:
		ImageLoader();
		virtual ~ImageLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, render::CtrlImage, ELEMENT_NAME_IMAGE);
	};
}