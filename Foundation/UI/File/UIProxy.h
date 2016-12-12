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
	public:
		UIProxy();
		virtual ~UIProxy();
	public:
		static UIProxy* getInstance();
		/**
		*	����ui�����ļ�
		*/
		Widget* loadFile(const char* filepath);
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

		typedef std::map<std::string, WidgetParser*> NodeParsers;
		// �ڵ��������
		NodeParsers _nodeParsers;
	}; 

	#define G_UIPROXY sys::Instance<UIProxy>::getInstance()
}