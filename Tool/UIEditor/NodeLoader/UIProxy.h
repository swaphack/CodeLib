#pragma once

#include "macros.h"
#include "INodeLoader.h"

namespace ui
{
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
		void registerNodeParser(const char* name, INodeLoader* parser);
	private:
		// ���ؽڵ�
		render::Node* loadNode(tinyxml2::XMLElement* pXmlNode);

		std::map<std::string, INodeLoader*> _nodeParsers;
	}; 

	#define G_UIPROXY sys::Instance<UIProxy>::getInstance()
}