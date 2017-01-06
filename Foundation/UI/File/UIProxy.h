#pragma once

#include "macros.h"
#include "Parse/import.h"
#include "Load/import.h"

namespace ui
{
	/**
	*	Ԫ������
	*/
	enum ElementType
	{
		/**
		*	δ����
		*/
		EET_NONE,
		/**
		*	�ؼ�
		*/
		EET_WIDGET,
		/**
		*	���ֽڵ�
		*/
		EET_LAYOUTITEM,
		/**
		*	����
		*/
		EET_LAYOUT,
	};

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
		bool saveFile(Layout* layout, const char* filepath);
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
		IElement* loadSingleElement(tinyxml2::XMLElement* xmlNode, ElementType& type);
		// ���ز��ֽڵ�
		bool loadLayoutItem(LayoutItemLoader* loader, tinyxml2::XMLElement* xmlNode);
		// ���ز���
		bool loadLayout(LayoutLoader* loader, tinyxml2::XMLElement* xmlNode);
		// ���ظ�Ԫ��
		IElement* loadRoot(tinyxml2::XMLElement* xmlNode);
		//////////////////////////////////////////////////////////////////////////
		// ����ڵ�
		bool saveWidget(Widget* widget, tinyxml2::XMLElement* xmlNode);
		// ���沼����
		bool saveLayoutItem(LayoutItem* layoutItem, tinyxml2::XMLElement* xmlNode);
		// ���沼��
		bool saveLayout(Layout* layout, tinyxml2::XMLElement* xmlNode);
		// �����Ԫ��
		bool saveRoot(Layout* layout, tinyxml2::XMLDocument* document);
	private:
		typedef std::map<std::string, IElement*> ElementParsers;
		// �ڵ��������
		ElementParsers _elementParsers;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}