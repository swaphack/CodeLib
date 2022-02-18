#include "IElement.h"

using namespace ui;

IElement::IElement()
{
	_nodeProperty = new WidgetProperty();
}

IElement::~IElement()
{
	SAFE_DELETE(_nodeProperty);
}

bool IElement::load(tinyxml2::XMLElement* pXmlNode, const math::Size& parentSize, bool clean/* = true*/)
{
	if (pXmlNode == nullptr)
	{
		return false;
	}
	//this->setWidget(nullptr);
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
	this->setParentSize(parentSize);

	this->initWidget();

	std::string name = pXmlNode->Name();
	_nodeProperty->setName(name);
	if (_node)
	{
		auto layoutItem = getLayoutItem();
		if (layoutItem) 
		{ 
			layoutItem->setWidgetName(name); 
		}
	}

	this->parseAttributes();

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
	auto layoutItem = _node->getLayoutItem();
	if (layoutItem)
	{
		pXmlNode->SetName(layoutItem->getWidgetName().c_str());
	}
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

const std::string& ui::IElement::getFontPath() const
{
	return _defaultFontPath;
}

void ui::IElement::setFontPath(const std::string& fontPath)
{
	_defaultFontPath = fontPath;
}

const std::string& ui::IElement::getFontImagePath() const
{
	return _defaultFontImagePath;
}

void ui::IElement::setFontImagePath(const std::string& fontImagePath)
{
	_defaultFontImagePath = fontImagePath;
}

const math::Size& ui::IElement::getParentSize() const
{
	return _parentSize;
}

void ui::IElement::setParentSize(const math::Size& size)
{
	_parentSize = size;
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

LayoutItem* ui::IElement::getLayoutItem()
{
	if (_node == nullptr) return nullptr;
	return _node->getLayoutItem();
}
