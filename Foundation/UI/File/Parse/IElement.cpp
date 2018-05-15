#include "IElement.h"
#include "text.h"
#include "Layout/LayoutItem.h"

using namespace ui;

IElement::IElement()
{
	_nodeProperty = new WidgetProperty();
}

IElement::~IElement()
{
	SAFE_DELETE(_nodeProperty);
}

bool IElement::load(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}
	if (clean)
	{
		_nodeProperty->Clear();
	}

	tinyxml2::XMLAttribute* pAttribute = (tinyxml2::XMLAttribute*)pXmlNode->FirstAttribute();

	while (pAttribute)
	{
		getNodeProperty()->setAttribute(pAttribute->Name(), pAttribute->Value());

		pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();
	}

	initLayoutItem();
	initWidget();

	this->parseAttributes();

	if (getLayoutItem())
	{
		getLayoutItem()->setWidget(getWidget());
		getLayoutItem()->setName(pXmlNode->Name());
	}

	return true;
}

bool IElement::save(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}

	if (clean)
	{
		_nodeProperty->Clear();
	}

	this->saveAttributes();

	pXmlNode->SetName(getNodeProperty()->getName());

	Attributes::const_iterator iterFirst = getNodeProperty()->getAttributeBegin();
	Attributes::const_iterator iterEnd = getNodeProperty()->getAttributeEnd();

	while (iterFirst != iterEnd)
	{
		pXmlNode->SetAttribute(iterFirst->first.c_str(), iterFirst->second.c_str());
		iterFirst++;
	}

	return true;
}

WidgetProperty* IElement::getNodeProperty()
{
	return _nodeProperty;
}

void IElement::setWidget(Widget* node)
{
	_node = node;
}

void IElement::setLayoutItem(LayoutItem* item)
{
	_layoutItem = item;
}

LayoutItem* ui::IElement::getLayoutItem()
{
	return _layoutItem;
}

Widget* ui::IElement::getWidget()
{
	return _node;
}
