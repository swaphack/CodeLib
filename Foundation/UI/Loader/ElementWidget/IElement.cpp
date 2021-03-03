#include "IElement.h"

using namespace ui;

IElement::IElement()
{
	_nodeProperty = new WidgetProperty();
}

IElement::~IElement()
{
	SAFE_DELETE(_nodeProperty);

	SAFE_RELEASE(_node);
}

bool IElement::load(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}

	this->setWidget(nullptr);
	if (clean)
	{
		_nodeProperty->Clear();
	}

	tinyxml2::XMLAttribute* pAttribute = (tinyxml2::XMLAttribute*)pXmlNode->FirstAttribute();

	while (pAttribute != nullptr)
	{
		getNodeProperty()->setAttribute(std::string(pAttribute->Name()), std::string(pAttribute->Value()));

		pAttribute = (tinyxml2::XMLAttribute*)pAttribute->Next();
	}

	initLayoutItem();
	initWidget();

	this->parseAttributes();

	std::string name = pXmlNode->Name();

	_nodeProperty->setName(name);
	if (_layoutItem && _node)
	{
		_layoutItem->setWidgetName(name);
		_node->setLayoutItem(_layoutItem);
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

	pXmlNode->SetName(_layoutItem->getWidgetName().c_str());
	//pXmlNode->SetName(getNodeProperty()->getName().c_str());

	Attributes::const_iterator iterFirst = getNodeProperty()->getAttributeBegin();
	Attributes::const_iterator iterEnd = getNodeProperty()->getAttributeEnd();

	while (iterFirst != iterEnd)
	{
		pXmlNode->SetAttribute(iterFirst->first.c_str(), iterFirst->second.c_str());
		iterFirst++;
	}

	return true;
}

void ui::IElement::setFontPath(const std::string& fontPath)
{
	_defaultFontPath = fontPath;
}

WidgetProperty* IElement::getNodeProperty()
{
	return _nodeProperty;
}

void IElement::setWidget(CtrlWidget* node)
{
	_node = node;
}

ui::CtrlWidget* ui::IElement::getWidget()
{
	return _node;
}

void ui::IElement::setLayoutItem(LayoutItem* item)
{
	_layoutItem = item;
}

LayoutItem* ui::IElement::getLayoutItem()
{
	return _layoutItem;
}

const std::string& ui::IElement::getFontPath()
{
	return _defaultFontPath;
}
