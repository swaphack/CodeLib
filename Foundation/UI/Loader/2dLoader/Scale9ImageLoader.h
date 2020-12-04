#pragma once

#include "ImageLoader.h"

namespace ui
{
	// ͼƬ
	class Scale9ImageLoader : public ImageLoader
	{
	public:
		Scale9ImageLoader();
		virtual ~Scale9ImageLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, render::CtrlScale9Image, ELEMENT_NAME_SCALE9_IMAGE);
	};
}