#pragma once


#include "LayoutLoader.h"

namespace ui
{
	// ͼƬ
	class ScrollViewLoader : public LayoutLoader
	{
	public:
		ScrollViewLoader();
		virtual ~ScrollViewLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(Layout, render::CtrlScrollView, ELEMENT_NAME_SCROLLVIEW);
	};
}
