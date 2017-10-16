#pragma once

#include "WidgetProperty.h"
#include "text.h"
#include "macros.h"

namespace ui
{
	class LayoutItem;

	// �ڵ������
	class IElement
	{
	public:
		IElement();
		virtual ~IElement();
	public:
		// ���ؽڵ�
		bool load(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// ����ڵ�
		bool save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// �����ڵ������
		virtual const char* getName() = 0;
		// ���ò��ֽڵ�
		void setLayoutItem(LayoutItem* item);
		// ����ui�ڵ�
		void setWidget(Widget* node);
		// ��ȡ����
		LayoutItem* getLayoutItem();
		// ��ȡ�ؼ�
		Widget* getWidget();
	protected:
		// ����
		WidgetProperty* getNodeProperty();
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
		// ��ʼ������
		virtual void initLayoutItem() = 0;
		// ��ʼ���ؼ�
		virtual void initWidget() = 0;
	private:
		// �ڵ�����
		WidgetProperty* _nodeProperty;
	protected:
		Widget* _node = nullptr;
		LayoutItem* _layoutItem = nullptr;
	};
}