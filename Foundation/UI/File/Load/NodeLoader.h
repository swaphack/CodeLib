#pragma once

#include "define.h"

namespace ui
{
	// ���ֽڵ�
	class NodeLoader : public IElement
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
		INIT_LOADER_WIDGET(LayoutItem, Widget, ELEMENT_NAME_LAYOUT);
	};
}