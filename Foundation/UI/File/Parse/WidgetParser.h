#pragma once

#include "IElement.h"
#include "macros.h"

namespace ui
{
	// �ڵ������
	class WidgetParser : public IElement
	{
	public:
		WidgetParser();
		virtual ~WidgetParser();
	public:
		// ����ui�ڵ�
		void setWidget(Widget* widget);
		// ��ȡui�ڵ�
		virtual Widget* getWidget() = 0;

		// �����ڵ������
		virtual const char* getName() = 0;
	protected:
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
	protected:
		// ui�ڵ�
		Widget* _node;
	};
}