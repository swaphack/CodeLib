#pragma once

#include "Parse/import.h"
#include "Load/import.h"
#include "text.h"
#include "ui_common.h"

namespace ui
{
	// ui����
	class UIProxy
	{
	private:
		UIProxy();
		virtual ~UIProxy();
	public:
		static UIProxy* getInstance();
		/**
		*	����ui�����ļ�
		*/
		Layout* loadFile(const char* filepath);
		/**
		*	����ui�����ļ�
		*/
		bool saveFile(Layout* layout, const char* filepath, const math::Size& designSize);
		/**
		*	ע��ڵ����
		*/
		void registerElementParser(const char* name, IElement* parser);
		/**
		*	ע���ڵ����
		*/
		void unregisterElementParser(const char* name);
		/**
		*	�Ƴ����нڵ����
		*/
		void removeAllElementParsers();
		/**
		*	��ƴ�С
		*/
		const math::Size& getDesignSize();
		/**
		*	��ȡ���ַ���
		*/
		LayoutDirection getDesignDirection();
	protected:
		/**
		*	��ʼ��
		*/
		void init();
		/**
		*	��ȡ�ڵ�
		*/
		IElement* getElement(const char* name);
	protected:
		//////////////////////////////////////////////////////////////////////////
		// ���ص�һ�ڵ�
		LayoutItem* initLoadItem(tinyxml2::XMLElement* xmlNode);
		// ���ز���
		bool loadLayout(Layout* loader, tinyxml2::XMLElement* xmlNode);
		// ���ظ�Ԫ��
		Layout* loadRoot(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// ����ڵ�
		bool saveWidget(Widget* widget, tinyxml2::XMLElement* xmlNode);
		// ���沼��
		bool saveLayoutItem(LayoutItem* item, tinyxml2::XMLElement* xmlNode);
		// �����Ԫ��
		bool saveRoot(Layout* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// �ڵ��������
		ElementParsers _elementParsers;
		// ��ƴ�С
		math::Size _designSize;
		// ���ַ���
		LayoutDirection _designDirection;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}