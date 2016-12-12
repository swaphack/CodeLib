#include "UIProxy.h"
#include "../Widget/import.h"

using namespace ui;


UIProxy::UIProxy()
{

}

UIProxy::~UIProxy()
{
	removeAllNodeParsers();
}

UIProxy* UIProxy::getInstance()
{
	static UIProxy* s_UIProxy = nullptr;
	if (s_UIProxy == nullptr)
	{
		s_UIProxy = new UIProxy();
	}

	return s_UIProxy;
}

Widget* UIProxy::loadFile(const char* filepath)
{
	if (filepath == nullptr)
	{
		return nullptr;
	}

	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	if (doc->Parse(filepath) != tinyxml2::XML_SUCCESS)
	{
		delete doc;
		return nullptr;
	}

	tinyxml2::XMLElement* pRoot = doc->RootElement();
	if (pRoot == nullptr)
	{
		delete doc;
		return nullptr;
	}

	Widget* pNode = this->loadNode(pRoot);

	delete doc;

	return pNode;
}

void UIProxy::registerNodeParser(const char* name, WidgetParser* parser)
{
	if (name == nullptr || parser == NULL)
	{
		return;
	}

	unregisterNodeParser(name);

	_nodeParsers[name] = parser;
}

void UIProxy::unregisterNodeParser(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	NodeParsers::const_iterator iter = _nodeParsers.find(name);
	if (iter == _nodeParsers.end())
	{
		return;
	}

	delete iter->second;
	_nodeParsers.erase(iter);
}

void UIProxy::removeAllNodeParsers()
{
	NodeParsers::const_iterator iter = _nodeParsers.begin();
	while (iter != _nodeParsers.end())
	{
		delete iter->second;
		iter++;
	}

	_nodeParsers.clear();
}

Widget* UIProxy::loadWidget(tinyxml2::XMLElement* pXmlNode)
{
	if (pXmlNode == nullptr)
	{
		return nullptr;
	}

	NodeParsers::const_iterator iter = _nodeParsers.find(pXmlNode->Name());
	if (iter == _nodeParsers.end())
	{
		return nullptr;
	}

	Widget* pWidget = iter->second->load(pXmlNode);
	if (pWidget == nullptr)
	{
		return nullptr;
	}

	Widget* pChildNode;
	tinyxml2::XMLElement* pChildXml = pXmlNode->FirstChildElement();
	while (pChildXml)
	{
		pChildNode = this->loadWidget(pChildXml);
		if (pChildNode)
		{
			pWidget->addChild(pChildNode);
		}
		pChildXml = pChildXml->NextSiblingElement();
	}

	return pWidget;
}
