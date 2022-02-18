#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// ͼƬ
	class Scale9ImageLoader : public WidgetLoader
	{
	public:
		Scale9ImageLoader();
		virtual ~Scale9ImageLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(CtrlScale9Image, ELEMENT_NAME_SCALE9_IMAGE);
	};
}