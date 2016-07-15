#include "UIProxy.h"

using namespace ui;


UIProxy::UIProxy()
{

}

UIProxy::~UIProxy()
{

}

render::Node* UIProxy::loadFile(const char* filepath)
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

	render::Node* pNode = this->loadNode(pRoot);

	delete doc;

	return pNode;
}

void UIProxy::registerNodeParser(const char* name, INodeLoader* parser)
{
	if (name == nullptr || parser == NULL)
	{
		return;
	}

	_nodeParsers[name] = parser;
}

render::Node* UIProxy::loadNode(tinyxml2::XMLElement* pXmlNode)
{
	if (pXmlNode == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, INodeLoader*>::const_iterator iter = _nodeParsers.find(pXmlNode->Name());
	if (iter == _nodeParsers.end())
	{
		return nullptr;
	}

	render::Node* pNode = iter->second->load(pXmlNode);
	if (pNode == nullptr)
	{
		return nullptr;
	}

	render::Node* pChildNode;
	tinyxml2::XMLElement* pChildXml = pXmlNode->FirstChildElement();
	while (pChildXml)
	{
		pChildNode = this->loadNode(pChildXml);
		if (pChildNode)
		{
			pNode->addChild(pChildNode);
		}
		pChildXml = pChildXml->NextSiblingElement();
	}

	return pNode;
}
