#pragma once

#include "define.h"

namespace ui
{
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