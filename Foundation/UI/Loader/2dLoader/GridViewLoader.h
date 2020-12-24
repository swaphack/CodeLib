#pragma once

#include "ListViewLoader.h"

namespace ui
{
	// �б�
	class GridViewLoader : public ListViewLoader
	{
	public:
		GridViewLoader();
		virtual ~GridViewLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, CtrlGridView, ELEMENT_NAME_GRIDVIEW);
	};
}