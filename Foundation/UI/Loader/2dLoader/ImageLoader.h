#pragma once

#include "WidgetLoader.h"

namespace ui
{
	// 图片
	class ImageLoader : public WidgetLoader
	{
	public:
		ImageLoader();
		virtual ~ImageLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(CtrlImage, ELEMENT_NAME_IMAGE);
	};
}