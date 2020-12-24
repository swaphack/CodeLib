#pragma once

#include "ScrollViewLoader.h"

namespace ui
{
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
		INIT_LOADER_WIDGET(LayoutItem, CtrlListView, ELEMENT_NAME_LISTVIEW);
	};
}