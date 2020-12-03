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
	SAFE_RELEASE(_layoutItem);
}

bool IElement::load(tinyxml2::XMLElement* pXmlNode, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}

	this->setLayoutItem(nullptr);
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

	_nodeProperty->setName(pXmlNode->Name());
	if (getLayoutItem())
	{
		getLayoutItem()->setWidgetName(pXmlNode->Name());
		getLayoutItem()->setWidget(getWidget());
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

	pXmlNode->SetName(getNodeProperty()->getName().c_str());

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

void IElement::setWidget(render::CtrlWidget* node)
{
	//SAFE_RETAIN(node);
	//SAFE_RELEASE(_node);

	_node = node;
}

void IElement::setLayoutItem(LayoutItem* item)
{
	//SAFE_RETAIN(item);
	//SAFE_RELEASE(_layoutItem);

	_layoutItem = item;
}

LayoutItem* ui::IElement::getLayoutItem()
{
	return _layoutItem;
}

render::CtrlWidget* ui::IElement::getWidget()
{
	return _node;
}

const std::string& ui::IElement::getFontPath()
{
	return _defaultFontPath;
}
