#pragma once

#include "macros.h"

using namespace render;

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
	private:
		INIT_LOADER_WIDGET(Widget);
	};
}