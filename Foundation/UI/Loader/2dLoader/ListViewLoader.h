#pragma once

#include "ScrollViewLoader.h"

namespace ui
{
	class Layout;
	// �б�
	class ListViewLoader : public ScrollViewLoader
	{
	public:
		ListViewLoader();
		virtual ~ListViewLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(Layout, render::CtrlListView, ELEMENT_NAME_LISTVIEW);
	};
}