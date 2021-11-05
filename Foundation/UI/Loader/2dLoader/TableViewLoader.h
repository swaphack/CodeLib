#pragma once

#include "ScrollViewLoader.h"

namespace ui
{
	// �б�
	class TableViewLoader : public ScrollViewLoader
	{
	public:
		TableViewLoader();
		virtual ~TableViewLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlTableView, ELEMENT_NAME_TABLEVIEW);
	};
}