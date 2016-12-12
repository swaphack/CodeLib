#include "WidgetParser.h"

using namespace ui;

WidgetParser::WidgetParser()
{
	_nodeProperty = new WidgetProperty();
}

WidgetParser::~WidgetParser()
{
	SAFE_DELETE(_nodeProperty);
}

Widget* WidgetParser::load(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
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

	return getWidget();
}

void WidgetParser::save(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
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

WidgetProperty* WidgetParser::getNodeProperty()
{
	return _nodeProperty;
}

void WidgetParser::parseAttributes()
{

}

void WidgetParser::saveAttributes()
{

}
