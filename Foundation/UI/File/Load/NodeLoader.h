#pragma once

#include "macros.h"

namespace ui
{
	// UI�ڵ�
	class NodeLoader : public WidgetParser
	{ 
	public:
		NodeLoader();
		virtual ~NodeLoader();
	protected:
		// ��������
		virtual void parseAttributes();
		// ��������
		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(Widget, ELEMENT_NAME_WIDGET);
	};
}