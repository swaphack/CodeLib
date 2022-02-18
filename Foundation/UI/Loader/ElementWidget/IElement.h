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
		bool load(tinyxml2::XMLElement* pXmlNode, const math::Size& parentSize, bool clean = true);
		// ����ڵ�
		bool save(tinyxml2::XMLElement* pXmlNode, bool clean = true);
		// �����ڵ������
		virtual std::string getName() = 0;
		// ����ui�ڵ�
		void setWidget(CtrlWidget* node);
		// ��ȡ�ؼ�
		CtrlWidget* getWidget();
		// ��ȡ����
		LayoutItem* getLayoutItem();
		/**
		*	Ĭ������
		*/
		const std::string& getFontPath() const;
		/**
		*	����Ĭ������
		*/
		void setFontPath(const std::string& fontPath);
		/**
		*	Ĭ������Image
		*/
		const std::string& getFontImagePath() const;
		/**
		*	����Ĭ������Image
		*/
		void setFontImagePath(const std::string& fontImagePath);
		/**
		*	Ĭ������
		*/
		const math::Size& getParentSize() const;
		/**
		*	����Ĭ������
		*/
		void setParentSize(const math::Size& size);
	protected:
		// ����
		WidgetProperty* getNodeProperty();
		// ��������
		virtual void parseAttributes() = 0;
		// ��������
		virtual void saveAttributes() = 0;
		// ��ʼ���ؼ�
		virtual void initWidget() = 0;
	private:
		// �ڵ�����
		WidgetProperty* _nodeProperty;
	protected:
		// ui�ؼ�
		CtrlWidget* _node = nullptr;
		// Ĭ������
		std::string _defaultFontPath;
		// Ĭ������ͼƬ
		std::string _defaultFontImagePath;
		// ���ڵ��С
		math::Size _parentSize;
	};
}