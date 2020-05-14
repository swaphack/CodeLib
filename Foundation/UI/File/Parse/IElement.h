#pragma once

#include "WidgetProperty.h"
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
		virtual std::string getName() = 0;
		// ���ò��ֽڵ�
		void setLayoutItem(LayoutItem* item);
		// ����ui�ڵ�
		void setWidget(render::CtrlWidget* node);
		// ��ȡ����
		LayoutItem* getLayoutItem();
		// ��ȡ�ؼ�
		render::CtrlWidget* getWidget();
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
		render::CtrlWidget* _node = nullptr;
		LayoutItem* _layoutItem = nullptr;
	};
}