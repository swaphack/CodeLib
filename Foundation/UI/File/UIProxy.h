#pragma once

#include "macros.h"
#include "Parse/import.h"
#include "Load/import.h"

namespace ui
{
	class WidgetParser;

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
		Widget* loadFile(const char* filepath);
		/**
		*	����ui�����ļ�
		*/
		bool saveFile(Widget* widget, const char* filepath);
		/**
		*	ע��ڵ����
		*/
		void registerNodeParser(const char* name, WidgetParser* parser);
		/**
		*	ע���ڵ����
		*/
		void unregisterNodeParser(const char* name);
		/**
		*	�Ƴ����нڵ����
		*/
		void removeAllNodeParsers();
	private:
		// ���ؽڵ�
		Widget* loadWidget(tinyxml2::XMLElement* pXmlNode);

		// ���ؽڵ�
		tinyxml2::XMLElement* saveWidget(tinyxml2::XMLDocument* pDocument, Widget* pWidget);

		typedef std::map<std::string, WidgetParser*> NodeParsers;
		// �ڵ��������
		NodeParsers _nodeParsers;
	}; 

	#define G_UIPROXY UIProxy::getInstance()
}