#include "UIProxy.h"
#include "Layout/import.h"
#include "Loader/import.h"

using namespace ui;

#define LAYOUT_ROOT_NAME	"root"
#define LAYOUT_SIZE_WIDTH	"width"
#define LAYOUT_SIZE_HEIGHT	"height"
#define LAYOUT_DIRECTION	"layout"
#define LAYOUT_FONT_PATH	"fontPath"


void UIProxy::init()
{

	this->registerElementParser(ELEMENT_NAME_WIDGET, new TextLoader());
	this->registerElementParser(ELEMENT_NAME_LAYOUT, new LayoutLoader());
	this->registerElementParser(ELEMENT_NAME_IMAGE, new ImageLoader());
	this->registerElementParser(ELEMENT_NAME_TEXT, new TextLoader());
	this->registerElementParser(ELEMENT_NAME_BUTTON, new ButtonLoader());
	this->registerElementParser(ELEMENT_NAME_EDITTEXT, new EditTextLoader());
	this->registerElementParser(ELEMENT_NAME_SCROLLVIEW, new ScrollViewLoader());

	this->registerElementParser(ELEMENT_NAME_FILE, new FileLoader());
}

// 获取控件名称
std::string getLayoutItemName(LayoutItem* item)
{
	if (item == nullptr)
	{
		return "";
	}

	return item->getWdigetName();
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

Layout* UIProxy::loadFile(const std::string& filepath)
{
	if (filepath.empty())
	{
		return nullptr;
	}

	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(filepath.c_str()) != tinyxml2::XML_SUCCESS)
	{
		return nullptr;
	}

	tinyxml2::XMLElement* root = doc.RootElement();
	if (root == nullptr)
	{
		return nullptr;
	}

	Layout* pLayout = loadRoot(root);
	if (pLayout == nullptr)
	{
		return nullptr;
	}

	return pLayout;
}

bool UIProxy::saveFile(Layout* layout, const std::string& filepath, const math::Size& designSize)
{
	if (layout == nullptr || filepath.empty())
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

	bool result = tinyxml2::XML_SUCCESS == doc.SaveFile(filepath.c_str());

	return result;
}

void UIProxy::registerElementParser(const std::string& name, IElement* parser)
{
	if (name.empty() || parser == NULL)
	{
		return;
	}

	unregisterElementParser(name);

	_elementParsers[name] = parser;
}

void UIProxy::unregisterElementParser(const std::string& name)
{
	if (name.empty())
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

const math::Size& UIProxy::getDesignSize() const
{
	return _designSize;
}

LayoutDirection UIProxy::getDesignDirection() const
{
	return _designDirection;
}

const std::string& ui::UIProxy::getFontPath()
{
	return _defaultFontPath;
}

void ui::UIProxy::setFontPath(const std::string& fontPath)
{
	_defaultFontPath = fontPath;
}

IElement* UIProxy::getElement(const std::string& name)
{
	if (_elementParsers.find(name) == _elementParsers.end())
	{
		return nullptr;
	}

	return _elementParsers[name];
}

LayoutItem* UIProxy::initLayoutItem(tinyxml2::XMLElement* xmlNode)
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

	if (element == nullptr)
	{
		return nullptr;
	}

	element->setFontPath(_defaultFontPath);
	if (!element->load(xmlNode))
	{
		return nullptr;
	}
	return element->getLayoutItem();
}

bool UIProxy::loadLayout(Layout* pLayout, tinyxml2::XMLElement* xmlNode)
{
	if (pLayout == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	LayoutItem* childItem = nullptr;
	tinyxml2::XMLElement* childNode = xmlNode;
	while (childNode)
	{
		childItem = initLayoutItem(childNode);
		if (childItem)
		{
			pLayout->addItemWithWidget(childItem);

			Layout* childLayout = childItem->as<Layout>();
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

	int width = xmlNode->IntAttribute(LAYOUT_SIZE_WIDTH);
	int height = xmlNode->IntAttribute(LAYOUT_SIZE_HEIGHT);

	_designSize.setWidth(width);
	_designSize.setHeight(height);

	width = _designSize.getWidth();
	height = _designSize.getHeight();

	_designDirection = (LayoutDirection)xmlNode->IntAttribute(LAYOUT_DIRECTION);
	if (xmlNode->Attribute(LAYOUT_FONT_PATH))
	{
		_defaultFontPath = xmlNode->Attribute(LAYOUT_FONT_PATH);
	}

	tinyxml2::XMLElement* firstChild = xmlNode->FirstChildElement();
	if (firstChild == nullptr)
	{
		return nullptr;
	}

	LayoutItem* pRootItem = initLayoutItem(firstChild);
	if (pRootItem == nullptr)
	{// 空节点
		return nullptr;
	}

	Layout* pLayout = pRootItem->as<Layout>();
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

	const std::string& name = getLayoutItemName(item);
	if (name.empty())
	{
		return false;
	}

	IElement* pElement = getElement(name);
	if (pElement == nullptr)
	{
		return false;
	}

	pElement->setLayoutItem(item);
	pElement->setWidget(item->getWidget());
	pElement->save(xmlNode);

	LayoutLoader* pLoader = pElement->as<LayoutLoader>();
	if (pLoader == nullptr)
	{
		return true;
	}

	Layout* layout = item->as<Layout>();
	if (layout == nullptr)
	{
		return true;
	}

	std::vector<LayoutItem*>::const_iterator iter = layout->getAllItems().begin();
	while (iter != layout->getAllItems().end())
	{
		tinyxml2::XMLElement* pChildNode = nullptr;

		std::string wName = getLayoutItemName(*iter);
		if (wName.empty())
		{
			continue;
		}
		pChildNode = xmlNode->GetDocument()->NewElement(wName.c_str());
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
	pRootNode->SetAttribute(LAYOUT_DIRECTION, (int)_designDirection);
	pRootNode->SetAttribute(LAYOUT_FONT_PATH, _defaultFontPath.c_str());
	document->InsertEndChild(pRootNode);

	tinyxml2::XMLElement* pChildNode = document->NewElement(ELEMENT_NAME_LAYOUT);
	pRootNode->InsertEndChild(pChildNode);
	return saveLayoutItem(layout, pChildNode);
}
