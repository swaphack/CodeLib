#include "UIProxy.h"
using namespace ui;

#define LAYOUT_ROOT_NAME	"root"
#define LAYOUT_SIZE_WIDTH	"width"
#define LAYOUT_SIZE_HEIGHT	"height"
#define LAYOUT_DIRECTION	"direction"

void UIProxy::init()
{
	//this->registerElementParser(ELEMENT_NAME_LAYOUTITEM, new LayoutItemLoader());
	//this->registerElementParser(ELEMENT_NAME_LAYOUT, new LayoutLoader());
	this->registerElementParser(ELEMENT_NAME_LAYOUT, new LayoutLoader());
	this->registerElementParser(ELEMENT_NAME_TEXT, new TextLoader());
	this->registerElementParser(ELEMENT_NAME_IMAGE, new ImageLoader());

	//this->registerElementParser(ELEMENT_NAME_HLAYOUT, new HLayoutLoader());
	//this->registerElementParser(ELEMENT_NAME_VLAYOUT, new VLayoutLoader());
}

// 获取控件名称
const char* getWidgetName(LayoutItem* item)
{
	if (item == nullptr)
	{
		return nullptr;
	}

	return item->getName();
}

// 获取布局名称
const char* getLayoutName(Layout* layout)
{
	if (layout == nullptr)
	{
		return nullptr;
	}

// 	if (dynamic_cast<HorizontalLayout*>(layout))
// 		return ELEMENT_NAME_HLAYOUT;
// 	else if (dynamic_cast<VerticalLayout*>(layout))
// 		return ELEMENT_NAME_VLAYOUT;
// 	else
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

	Layout* pLayout = loadRoot(pRoot);
	if (pLayout == nullptr)
	{
		return nullptr;
	}

	return pLayout;
}

bool UIProxy::saveFile(Layout* layout, const char* filepath, const math::Size& designSize)
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

const math::Size& UIProxy::getDesignSize()
{
	return _designSize;
}

LayoutDirection UIProxy::getDesignDirection()
{
	return _designDirection;
}

IElement* UIProxy::getElement(const char* name)
{
	if (_elementParsers.find(name) == _elementParsers.end())
	{
		return nullptr;
	}

	return _elementParsers[name];
}

LayoutItem* UIProxy::initLoadItem(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == nullptr)
	{
		return nullptr;
	}

	ElementParsers::const_iterator iter = _elementParsers.find(xmlNode->Name());
	if (iter == _elementParsers.end())
	{
		return nullptr;
	}
	IElement* element = iter->second;

	NodeLoader* loader = dynamic_cast<NodeLoader*>(element);
	if (loader == nullptr)
	{
		return nullptr;
	}

	loader->setLayoutItem(nullptr);
	loader->setWidget(nullptr);

	if (!loader->load(xmlNode))
	{
		return nullptr;
	}
	return loader->getLayoutItem();
}

bool UIProxy::loadLayout(Layout* loader, tinyxml2::XMLElement* xmlNode)
{
	if (loader == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	LayoutItem* childItem = nullptr;
	tinyxml2::XMLElement* childNode = xmlNode;
	while (childNode)
	{
		childItem = initLoadItem(childNode);
		if (childItem)
		{
			loader->addItem(childItem);
			Layout* childLayout = dynamic_cast<Layout*>(childItem);
			if (childNode->FirstChild() && childLayout)
			{
				loadLayout(childLayout, childNode->FirstChildElement());
			}
		}
		childNode = childNode->NextSiblingElement();
	}

	return true;
}

Layout* UIProxy::loadRoot(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == nullptr)
	{
		return nullptr;
	}

	_designSize.setWidth(xmlNode->IntAttribute(LAYOUT_SIZE_WIDTH));
	_designSize.setHeight(xmlNode->IntAttribute(LAYOUT_SIZE_HEIGHT));
	_designDirection = (LayoutDirection)xmlNode->IntAttribute(LAYOUT_DIRECTION);

	tinyxml2::XMLElement* firstChild = xmlNode->FirstChildElement();
	if (firstChild == nullptr)
	{
		return nullptr;
	}

	LayoutItem* pRootItem = initLoadItem(firstChild);
	if (pRootItem == nullptr)
	{// 空节点
		return nullptr;
	}

	Layout* pLayout = dynamic_cast<Layout*>(pRootItem);
	if (pLayout == nullptr)
	{// 非布局节点
		return nullptr;
	}

	loadLayout(pLayout, firstChild->FirstChildElement());

	return pLayout;
}

bool UIProxy::saveLayoutItem(LayoutItem* item, tinyxml2::XMLElement* xmlNode)
{
	if (item == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	const char* name = getWidgetName(item);
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
	pLoader->setLayoutItem(item);
	pLoader->setWidget(item->getWidget());
	pLoader->save(xmlNode);

	Layout* layout = dynamic_cast<Layout*>(item);
	if (layout == nullptr)
	{
		return true;
	}

	std::vector<LayoutItem*>::const_iterator iter = layout->getChildren().begin();
	while (iter != layout->getChildren().end())
	{
		tinyxml2::XMLElement* pChildNode = nullptr;

		name = getWidgetName(*iter);
		if (name == nullptr)
		{
			continue;
		}
		pChildNode = xmlNode->GetDocument()->NewElement(name);
		this->saveLayoutItem(*iter, pChildNode);

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
	pRootNode->SetAttribute(LAYOUT_SIZE_WIDTH, _designSize.getWidth());
	pRootNode->SetAttribute(LAYOUT_SIZE_HEIGHT, _designSize.getHeight());
	pRootNode->SetAttribute(LAYOUT_DIRECTION, _designDirection);
	document->InsertEndChild(pRootNode);

	tinyxml2::XMLElement* pChildNode = document->NewElement(ELEMENT_NAME_LAYOUT);
	pRootNode->InsertEndChild(pChildNode);
	return saveLayoutItem(layout, pChildNode);
}
