#pragma once

#include "Loader/ElementWidget/import.h"
#include "render.h"
#include "macros.h"
#include "UI/import.h"

namespace ui
{
	// �ؼ�
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
		INIT_LOADER_WIDGET(CtrlWidget, ELEMENT_NAME_WIDGET);
	};
}