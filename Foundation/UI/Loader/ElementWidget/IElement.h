#pragma once

#include "WidgetProperty.h"
#include "Layout/LayoutItem.h"
#include "UI/CtrlWidget.h"
#include "system.h"
#include "render.h"

namespace ui
{
	// �ڵ������
	class IElement : public sys::Object
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
		// ����ui�ڵ�
		void setWidget(CtrlWidget* node);
		// ��ȡ�ؼ�
		CtrlWidget* getWidget();

		void setLayoutItem(LayoutItem* item);

		LayoutItem* getLayoutItem();

		/**
		*	Ĭ������
		*/
		const std::string& getFontPath();
		/**
		*	����Ĭ������
		*/
		void setFontPath(const std::string& fontPath);
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
		CtrlWidget* _node = nullptr;

		LayoutItem* _layoutItem = nullptr;
		// Ĭ������
		std::string _defaultFontPath;
	};
}