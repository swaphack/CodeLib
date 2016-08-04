#pragma once

#include "macros.h"
#include "INodeParser.h"

namespace ui
{
	class INodeParser;

	// ui����
	class UIProxy
	{
	public:
		UIProxy();
		virtual ~UIProxy();
	public:
		// ����ui�����ļ�
		render::Node* loadFile(const char* filepath);
		// ע��ڵ����
		void registerNodeParser(const char* name, INodeParser* parser);
	private:
		// ���ؽڵ�
		render::Node* loadNode(tinyxml2::XMLElement* pXmlNode);

		std::map<std::string, INodeParser*> _nodeParsers;
	}; 

	#define G_UIPROXY sys::Instance<UIProxy>::getInstance()
}