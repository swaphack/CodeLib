#include "UIProxy.h"

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

	Widget* pNode = this->loadWidget(pRoot);

	delete doc;

	return pNode;
}

bool UIProxy::saveFile(Widget* widget, const char* filepath)
{
	if (widget == nullptr || filepath == nullptr)
	{
		return false;
	}

	tinyxml2::XMLDocument doc;

	if (!saveWidget(&doc, widget))
	{
		return false;
	}

	return tinyxml2::XML_SUCCESS == doc.SaveFile(filepath);
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

	if (!iter->second->load(pXmlNode))
	{
		return nullptr;
	}

	Widget* pWidget = iter->second->getWidget();
	iter->second->setWidget(nullptr);

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

tinyxml2::XMLElement* UIProxy::saveWidget(tinyxml2::XMLDocument* pDocument, Widget* pWidget)
{
	if (pDocument == nullptr || pWidget == nullptr)
	{
		return nullptr;
	}

	const char* name = typeid(pWidget).name();
	NodeParsers::const_iterator iter = _nodeParsers.find(name);
	if (iter == _nodeParsers.end())
	{
		return nullptr;
	}

	iter->second->setWidget(pWidget);
	tinyxml2::XMLElement* pXmlElement = pDocument->NewElement(name);
	if (!iter->second->save(pXmlElement))
	{
		pDocument->DeleteNode(pXmlElement);
		return nullptr;
	}

	std::vector<sys::Object*>::iterator begin = pWidget->beginChild();
	std::vector<sys::Object*>::iterator end = pWidget->endChild();

	while (begin != end)
	{
		tinyxml2::XMLElement* pChildNode = saveWidget(pDocument, pWidget);
		if (pChildNode)
		{
			pXmlElement->InsertEndChild(pChildNode);
		}
		begin++;
	}

	return pXmlElement;
}
