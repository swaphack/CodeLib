#include "INodeLoader.h"
#include "UIProxy.h"

using namespace ui;

INodeLoader::INodeLoader()
:_node(nullptr)
{
	_elementLoader = new NodeProperty();

	this->registerNodeParser();
}

INodeLoader::~INodeLoader()
{
	SAFE_DELETE(_elementLoader);
}

render::Node* INodeLoader::load(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return nullptr;
	}
	if (clean)
	{
		_elementLoader->Clear();
	}

	tinyxml2::XMLAttribute* pAttribute = (tinyxml2::XMLAttribute*)pXmlNode->FirstAttribute();

	getAttributeLoader()->setName(pXmlNode->Name());

	while (pAttribute)
	{
		getAttributeLoader()->setAttribute(pAttribute->Name(), pAttribute->Value());

		pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();
	}

	this->parseAttributes();

	return getNode();
}

void INodeLoader::save(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return;
	}

	if (clean)
	{
		_elementLoader->Clear();
	}

	this->saveAttributes();

	pXmlNode->SetName(getAttributeLoader()->getName());

	Attributes::const_iterator iterFirst = getAttributeLoader()->getAttributeFirst();
	Attributes::const_iterator iterEnd = getAttributeLoader()->getAttributeEnd();

	while (iterFirst != iterEnd)
	{
		pXmlNode->SetAttribute(iterFirst->first.c_str(), iterFirst->second.c_str());
		iterFirst++;
	}
}

NodeProperty* INodeLoader::getAttributeLoader()
{
	return _elementLoader;
}

void INodeLoader::parseAttributes()
{

}

void INodeLoader::saveAttributes()
{

}
