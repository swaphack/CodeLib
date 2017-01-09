#include "UIProxy.h"
using namespace ui;

#define LAYOUT_ROOT_NAME	"root"
#define LAYOUT_SIZE_WIDTH	"width"
#define LAYOUT_SIZE_Height	"height"

void UIProxy::init()
{
	this->registerElementParser(ELEMENT_NAME_LAYOUTITEM, new LayoutItemLoader());
	this->registerElementParser(ELEMENT_NAME_LAYOUT, new LayoutLoader());
	this->registerElementParser(ELEMENT_NAME_HLAYOUT, new HLayoutLoader());
	this->registerElementParser(ELEMENT_NAME_VLAYOUT, new VLayoutLoader());
	this->registerElementParser(ELEMENT_NAME_WIDGET, new NodeLoader());
	this->registerElementParser(ELEMENT_NAME_TEXT, new TextLoader());
	this->registerElementParser(ELEMENT_NAME_IMAGE, new ImageLoader());
}

// 获取控件名称
const char* getWidgetName(Widget* widget)
{
	if (widget == nullptr)
	{
		return nullptr;
	}

	if (dynamic_cast<CtrlText*>(widget))
		return ELEMENT_NAME_TEXT;
	else if (dynamic_cast<CtrlImage*>(widget))
		return ELEMENT_NAME_IMAGE;
	else
		return ELEMENT_NAME_WIDGET;
}

// 获取布局名称
const char* getLayoutName(Layout* layout)
{
	if (layout == nullptr)
	{
		return nullptr;
	}

	if (dynamic_cast<HorizontalLayout*>(layout))
		return ELEMENT_NAME_HLAYOUT;
	else if (dynamic_cast<VerticalLayout*>(layout))
		return ELEMENT_NAME_VLAYOUT;
	else
		return ELEMENT_NAME_LAYOUT;
}

//////////////////////////////////////////////////////////////////////////
UIProxy::UIProxy()
{

}

UIProxy::~UIProxy()
{
	removeAllElementParsers();
}

UIProxy* UIProxy::getInstance()
{
	static UIProxy* s_UIProxy = nullptr;
	if (s_UIProxy == nullptr)
	{
		s_UIProxy = new UIProxy();
		s_UIProxy->init();
	}

	return s_UIProxy;
}

Layout* UIProxy::loadFile(const char* filepath)
{
	if (filepath == nullptr)
	{
		return nullptr;
	}

	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(filepath) != tinyxml2::XML_SUCCESS)
	{
		return nullptr;
	}

	tinyxml2::XMLElement* pRoot = doc.RootElement();
	if (pRoot == nullptr)
	{
		return nullptr;
	}


	IElement* element = loadRoot(pRoot);
	if (element == nullptr)
	{
		return nullptr;
	}

	return static_cast<LayoutLoader*>(element)->getCastLayoutItem();
}

bool UIProxy::saveFile(Layout* layout, const char* filepath, const sys::Size& designSize)
{
	if (layout == nullptr || filepath == nullptr)
	{
		return false;
	}

	tinyxml2::XMLDocument doc;
	tinyxml2::XMLDeclaration* pDeclaration = doc.NewDeclaration("xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"");
	doc.InsertEndChild(pDeclaration);

	_designSize = designSize;

	if (!saveRoot(layout, &doc))
	{
		doc.Clear();
		return false;
	}

	bool result = tinyxml2::XML_SUCCESS == doc.SaveFile(filepath);

	return result;
}

void UIProxy::registerElementParser(const char* name, IElement* parser)
{
	if (name == nullptr || parser == NULL)
	{
		return;
	}

	unregisterElementParser(name);

	_elementParsers[name] = parser;
}

void UIProxy::unregisterElementParser(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	ElementParsers::const_iterator iter = _elementParsers.find(name);
	if (iter == _elementParsers.end())
	{
		return;
	}

	delete iter->second;
	_elementParsers.erase(iter);
}

void UIProxy::removeAllElementParsers()
{
	ElementParsers::const_iterator iter = _elementParsers.begin();
	while (iter != _elementParsers.end())
	{
		delete iter->second;
		iter++;
	}

	_elementParsers.clear();
}

const sys::Size& UIProxy::getDesignSize()
{
	return _designSize;
}

IElement* UIProxy::getElement(const char* name)
{
	if (_elementParsers.find(name) == _elementParsers.end())
	{
		return nullptr;
	}

	return _elementParsers[name];
}

IElement* UIProxy::loadSingleElement(tinyxml2::XMLElement* xmlNode, ElementType& type)
{
	type = EET_NONE;
	if (xmlNode == nullptr)
	{
		return nullptr;
	}

	ElementParsers::const_iterator iter = _elementParsers.find(xmlNode->Name());
	if (iter == _elementParsers.end())
	{
		return nullptr;
	}

	if (!iter->second->load(xmlNode))
	{
		return nullptr;
	}

	IElement* element = iter->second;
	// 空间节点
	NodeLoader* widgetLoader = dynamic_cast<NodeLoader*>(element);
	if (widgetLoader != nullptr)
	{
		type = EET_WIDGET;
		return widgetLoader;
	}
	// 布局节点
	LayoutLoader* layoutLoader = dynamic_cast<LayoutLoader*>(element);
	if (layoutLoader != nullptr)
	{
		type = EET_LAYOUT;
		return layoutLoader;
	}
	// 布局节点
	LayoutItemLoader* layoutItemLoader = dynamic_cast<LayoutItemLoader*>(element);
	if (layoutItemLoader != nullptr)
	{
		type = EET_LAYOUTITEM;
		return layoutItemLoader;
	}

	return nullptr;
}

bool UIProxy::loadLayoutItem(LayoutItemLoader* loader, tinyxml2::XMLElement* xmlNode)
{
	if (loader == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	ElementType childType = EET_NONE;
	IElement* childElement = nullptr;
	tinyxml2::XMLElement* pChildNode = xmlNode->FirstChildElement();
	while (pChildNode)
	{
		childElement = loadSingleElement(pChildNode, childType);
		if (childElement == nullptr || childType != EET_WIDGET)
		{
			return false;
		}

		NodeLoader* pChildNodeLoader = dynamic_cast<NodeLoader*>(childElement);
		if (pChildNodeLoader)
		{
			loader->getCastLayoutItem()->setWidget(pChildNodeLoader->getCastWidget());
		}

		pChildNode = pChildNode->NextSiblingElement();
	}

	return true;
}

bool UIProxy::loadLayout(LayoutLoader* loader, tinyxml2::XMLElement* xmlNode)
{
	if (loader == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	ElementType childType = EET_NONE;
	IElement* childElement = nullptr;

	while (xmlNode)
	{
		childElement = loadSingleElement(xmlNode->FirstChildElement(), childType);
		if (childElement && childType == EET_LAYOUTITEM)
		{
			LayoutItemLoader* pChildLayoutItemLoader = dynamic_cast<LayoutItemLoader*>(childElement);
			if (pChildLayoutItemLoader)
			{
				loadLayoutItem(pChildLayoutItemLoader, xmlNode->FirstChildElement());

				loader->getCastLayoutItem()->addItem(pChildLayoutItemLoader->getCastLayoutItem());
			}
		}
		else if (childElement && childType == EET_LAYOUT)
		{
			LayoutLoader* pChildLayoutLoader = dynamic_cast<LayoutLoader*>(childElement);
			if (pChildLayoutLoader)
			{
				loadLayout(pChildLayoutLoader, xmlNode->FirstChildElement());

				loader->getCastLayoutItem()->addItem(pChildLayoutLoader->getCastLayoutItem());
			}
		}
		xmlNode = xmlNode->NextSiblingElement();
	}

	return true;
}

IElement* UIProxy::loadRoot(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == nullptr)
	{
		return nullptr;
	}

	_designSize.width = xmlNode->IntAttribute("width");
	_designSize.height = xmlNode->IntAttribute("height");

	tinyxml2::XMLElement* firstChild = xmlNode->FirstChildElement();
	if (firstChild == nullptr)
	{
		return nullptr;
	}

	ElementType type;
	IElement* currentElement = loadSingleElement(firstChild, type);
	if (currentElement == nullptr || type != EET_LAYOUT)
	{// 空节点或者非布局节点
		return nullptr;
	}

	loadLayout(static_cast<LayoutLoader*>(currentElement), firstChild);

	return currentElement;
}

bool UIProxy::saveWidget(Widget* widget, tinyxml2::XMLElement* xmlNode)
{
	if (widget == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	const char* name = getWidgetName(widget);
	if (name == nullptr)
	{
		return false;
	}

	IElement* element = getElement(name);
	if (element == nullptr)
	{
		return false;
	}

	NodeLoader* pLoader = (NodeLoader*)(element);
	pLoader->setWidget(widget);
	pLoader->save(xmlNode);

	return true;
}

bool UIProxy::saveLayoutItem(LayoutItem* layoutItem, tinyxml2::XMLElement* xmlNode)
{
	if (layoutItem == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	IElement* pElement = getElement(ELEMENT_NAME_LAYOUTITEM);
	if (pElement == nullptr)
	{
		return false;
	}
	LayoutItemLoader* pLoader = dynamic_cast<LayoutItemLoader*>(pElement);
	if (pLoader == nullptr)
	{
		return false;
	}
	pLoader->setLayoutItem(layoutItem);
	pLoader->save(xmlNode);

	if (layoutItem->getWidget())
	{
		const char* name = getWidgetName(layoutItem->getWidget());
		if (name == nullptr)
		{
			return false;
		}
		tinyxml2::XMLElement* pChildNode = xmlNode->GetDocument()->NewElement(name);
		saveWidget(layoutItem->getWidget(), pChildNode);
		xmlNode->InsertEndChild(pChildNode);
	}

	return true;
}

bool UIProxy::saveLayout(Layout* layout, tinyxml2::XMLElement* xmlNode)
{
	if (layout == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	const char* name = getLayoutName(layout);
	if (name == nullptr)
	{
		return false;
	}

	IElement* pElement = getElement(name);
	if (pElement == nullptr)
	{
		return false;
	}
	LayoutLoader* pLoader = dynamic_cast<LayoutLoader*>(pElement);
	if (pLoader == nullptr)
	{
		return false;
	}
	pLoader->setLayoutItem(layout);
	pLoader->save(xmlNode);

	std::vector<LayoutItem*>::const_iterator iter = layout->getChildren().begin();
	while (iter != layout->getChildren().end())
	{
		tinyxml2::XMLElement* pChildNode = nullptr;
		if (dynamic_cast<Layout*>(*iter))
		{// 布局
			name = getLayoutName(dynamic_cast<Layout*>(*iter));
			if (name == nullptr)
			{
				return false;
			}
			pChildNode = xmlNode->GetDocument()->NewElement(name);
			this->saveLayout(dynamic_cast<Layout*>(*iter), pChildNode);
		}
		else
		{// 节点节点
			pChildNode = xmlNode->GetDocument()->NewElement(ELEMENT_NAME_LAYOUTITEM);
			this->saveLayoutItem(*iter, pChildNode);
		}

		xmlNode->InsertEndChild(pChildNode);
		iter++;
	}

	return true;
}

bool UIProxy::saveRoot(Layout* layout, tinyxml2::XMLDocument* document)
{
	if (layout == nullptr || document == nullptr)
	{
		return false;
	}

	tinyxml2::XMLElement* pRootNode = document->NewElement(LAYOUT_ROOT_NAME);
	pRootNode->SetAttribute(LAYOUT_SIZE_WIDTH, _designSize.width);
	pRootNode->SetAttribute(LAYOUT_SIZE_Height, _designSize.height);
	document->InsertEndChild(pRootNode);

	tinyxml2::XMLElement* pChildNode = document->NewElement(ELEMENT_NAME_LAYOUT);
	pRootNode->InsertEndChild(pChildNode);
	return saveLayout(layout, pChildNode);
}