#include "INodeParser.h"
#include "UIProxy.h"

using namespace ui;

INodeParser::INodeParser()
{
	_nodeProperty = new NodeProperty();
}

INodeParser::~INodeParser()
{
	SAFE_DELETE(_nodeProperty);
}

render::Node* INodeParser::load(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return nullptr;
	}
	if (clean)
	{
		_nodeProperty->Clear();
	}

	tinyxml2::XMLAttribute* pAttribute = (tinyxml2::XMLAttribute*)pXmlNode->FirstAttribute();

	getNodeProperty()->setName(pXmlNode->Name());

	while (pAttribute)
	{
		getNodeProperty()->setAttribute(pAttribute->Name(), pAttribute->Value());

		pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();
	}

	this->parseAttributes();

	return getNode();
}

void INodeParser::save(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return;
	}

	if (clean)
	{
		_nodeProperty->Clear();
	}

	this->saveAttributes();

	pXmlNode->SetName(getNodeProperty()->getName());

	Attributes::const_iterator iterFirst = getNodeProperty()->getAttributeFirst();
	Attributes::const_iterator iterEnd = getNodeProperty()->getAttributeEnd();

	while (iterFirst != iterEnd)
	{
		pXmlNode->SetAttribute(iterFirst->first.c_str(), iterFirst->second.c_str());
		iterFirst++;
	}
}

NodeProperty* INodeParser::getNodeProperty()
{
	return _nodeProperty;
}

void INodeParser::parseAttributes()
{

}

void INodeParser::saveAttributes()
{

}
