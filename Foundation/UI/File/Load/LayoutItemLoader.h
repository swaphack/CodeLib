#pragma once

#include "macros.h"

namespace ui
{
	// ���ֽڵ�
	class LayoutItemLoader : public WidgetParser
	{
	public:
		LayoutItemLoader();
		virtual ~LayoutItemLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	};
}