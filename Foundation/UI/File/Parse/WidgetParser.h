#pragma once

#include "helper.h"
#include "IElement.h"

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
		// ��ȡ������
		LayoutItem* getLayoutItem();

		// ��ȡui�ڵ�
		virtual Widget* getWidget() = 0;
	protected:
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
		// ע�����
		virtual void registerNodeParser() = 0;
	protected:
		// ui�ڵ�
		Widget* _node;
		// ������
		LayoutItem* _layoutItem;
	private:
		// �ڵ�����
		WidgetProperty* _nodeProperty;
	};
}