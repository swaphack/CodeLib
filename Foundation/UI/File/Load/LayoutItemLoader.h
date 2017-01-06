#pragma once

#include "macros.h"

namespace ui
{
#define ELEMENT_NAME_LAYOUTITEM		"LayoutItem"
	// ���ֽڵ�
	class LayoutItemLoader : public LayoutItemParser
	{
	public:
		LayoutItemLoader();
		virtual ~LayoutItemLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_LAYOUTITEM(LayoutItem, ELEMENT_NAME_LAYOUTITEM);
	};
}