#pragma once

#include "../ElementWidget/import.h"
#include "render.h"

namespace ui
{
	// ���ֽڵ�
	class WidgetLoader : public IElement
	{
	public:
		WidgetLoader();
		virtual ~WidgetLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(LayoutItem, render::CtrlWidget, ELEMENT_NAME_WIDGET);
	};
}