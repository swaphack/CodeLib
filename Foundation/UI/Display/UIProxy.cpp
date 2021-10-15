#include "UIProxy.h"
#include "Layout/import.h"
#include "Loader/import.h"
#include "UIShaderHelper.h"
#include "toollib.h"
using namespace ui;

#define LAYOUT_ROOT_NAME	"root"
#define LAYOUT_SIZE_WIDTH	"width"
#define LAYOUT_SIZE_HEIGHT	"height"
#define LAYOUT_DIRECTION	"layout"
#define LAYOUT_FONT_PATH	"fontPath"

#define TEXTURE_TYPE "type"
#define TEXTURE_TYPE_ATLAS "atlas"
#define TEXTURE_TYPE_IMAGE "image"

#define TEXTURE_IMAGE "image"
#define TEXTURE_ATLAS "atlas"




void UIProxy::init()
{

	this->registerElementParser(ELEMENT_NAME_WIDGET, []() { return new WidgetLoader(); });
	this->registerElementParser(ELEMENT_NAME_LAYOUT, []() { return new LayoutLoader(); });
	this->registerElementParser(ELEMENT_NAME_IMAGE, []() { return new ImageLoader(); });
	this->registerElementParser(ELEMENT_NAME_TEXT, []() { return new TextLoader(); });
	this->registerElementParser(ELEMENT_NAME_BUTTON, []() { return new ButtonLoader(); });
	this->registerElementParser(ELEMENT_NAME_EDITTEXT, []() { return new EditTextLoader(); });
	this->registerElementParser(ELEMENT_NAME_SCALE9_IMAGE, []() { return new Scale9ImageLoader(); });
	this->registerElementParser(ELEMENT_NAME_SCROLLVIEW, []() { return new ScrollViewLoader(); });
	this->registerElementParser(ELEMENT_NAME_LISTVIEW, []() { return new ListViewLoader(); });
	this->registerElementParser(ELEMENT_NAME_GRIDVIEW, []() { return new GridViewLoader(); });
	this->registerElementParser(ELEMENT_NAME_FILE, []() { return new FileLoader(); });
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

CtrlWidget* UIProxy::loadFile(const std::string& filepath, const math::Size& size)
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

	CtrlWidget* pLayout = loadRoot(root, size);
	if (pLayout == nullptr)
	{
		return nullptr;
	}

	return pLayout;
}

bool UIProxy::saveFile(CtrlWidget* layout, const std::string& filepath, const math::Size& designSize)
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

void UIProxy::registerElementParser(const std::string& name, const CreateElementFunc& func)
{
	if (name.empty() || func == nullptr)
	{
		return;
	}

	unregisterElementParser(name);

	_elementParsers[name] = func;
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

	_elementParsers.erase(iter);
}

void UIProxy::removeAllElementParsers()
{
	ElementParsers::const_iterator iter = _elementParsers.begin();
	while (iter != _elementParsers.end())
	{
		iter++;
	}

	_elementParsers.clear();
}

void ui::UIProxy::registerWidgetCreator(const std::string& creatorName, const CreateWidgetFunc& func)
{
	if (creatorName.empty() || func == NULL)
	{
		return;
	}

	unregisterWidgetCreator(creatorName);

	_widgetCreators[creatorName] = func;
}

void ui::UIProxy::unregisterWidgetCreator(const std::string& creatorName)
{
	if (creatorName.empty())
	{
		return;
	}

	WidgetCreators::const_iterator iter = _widgetCreators.find(creatorName);
	if (iter == _widgetCreators.end())
	{
		return;
	}
	_widgetCreators.erase(iter);
}

void ui::UIProxy::removeAllWidgetCreators()
{
	_widgetCreators.clear();
}

ui::CtrlWidget* ui::UIProxy::createWidget(const std::string& widgetName)
{
	for (auto item : _widgetCreators)
	{
		auto pWidget = item.second(widgetName);
		if (pWidget != nullptr)
		{
			return pWidget;
		}
	}

	return nullptr;
}

void ui::UIProxy::registerWidgetPropertyCreator(const std::string& creatorName, const CreateWidgetFunc& func)
{
	if (creatorName.empty() || func == NULL)
	{
		return;
	}

	unregisterWidgetPropertyCreator(creatorName);

	_widgetPropertyCreators[creatorName] = func;
}

void ui::UIProxy::unregisterWidgetPropertyCreator(const std::string& creatorName)
{
	if (creatorName.empty())
	{
		return;
	}

	WidgetCreators::const_iterator iter = _widgetPropertyCreators.find(creatorName);
	if (iter == _widgetPropertyCreators.end())
	{
		return;
	}
	_widgetPropertyCreators.erase(iter);
}

void ui::UIProxy::removeAllWidgetPropertyCreators()
{
	_widgetPropertyCreators.clear();
}

ui::CtrlWidget* ui::UIProxy::createWidgetProperty(const std::string& widgetName)
{
	for (auto item : _widgetPropertyCreators)
	{
		auto pWidget = item.second(widgetName);
		if (pWidget != nullptr)
		{
			return pWidget;
		}
	}

	return nullptr;
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

ui::LayoutItem* ui::UIProxy::getLayoutItem(ui::CtrlWidget* item)
{
	if (item == nullptr) return nullptr;
	return item->getLayoutItem();
}

std::string ui::UIProxy::getLayoutItemName(ui::CtrlWidget* item)
{
	if (item == nullptr) return "";

	auto pLayoutItem = getLayoutItem(item);
	if (pLayoutItem == nullptr) return "";
	return pLayoutItem->getWidgetName();
}

render::Node* ui::UIProxy::getChildByIndex(render::Node* node, int index)
{
	if (node == nullptr) return nullptr;

	std::vector<render::Node*> children;
	if (!getVisibleChildren(node, children))
	{
		return nullptr;
	}

	if (index < 0 || index >= children.size())
	{
		return nullptr;
	}

	return children.at(index);
}

bool ui::UIProxy::getVisibleChildren(const render::Node* node, std::vector<render::Node*>& children)
{
	if (node == nullptr) return false;

	render::Node* pNode = (render::Node*)(node);

	auto pScrollView = dynamic_cast<ui::CtrlScrollView*>(pNode);
	if (pScrollView)
	{
		int count = pScrollView->getItemCount();
		for (int i = 0; i < count; i++)
		{
			children.push_back(pScrollView->getItemByIndex(i));
		}

		return true;
	}

	auto pWidget = dynamic_cast<ui::CtrlWidget*>(pNode);
	if (pWidget)
	{
		int count = pWidget->getWidgetCount();
		for (int i = 0; i < count; i++)
		{
			children.push_back(pWidget->getWidgetByIndex(i));
		}

		return true;
	}

	int count = pNode->getChildrenCount();
	for (int i = 0; i < count; i++)
	{
		children.push_back(pScrollView->getChildByIndex(i));
	}

	return true;
}

IElement* UIProxy::getElement(const std::string& name)
{
	auto it = _elementParsers.find(name);
	if (it == _elementParsers.end())
	{
		return nullptr;
	}

	if (it->second == nullptr)
	{
		return nullptr;
	}

	return it->second();
}

CtrlWidget* UIProxy::initWidget(tinyxml2::XMLElement* xmlNode, const math::Size& parentSize)
{
	if (xmlNode == nullptr)
	{
		return nullptr;
	}

	IElement* element = getElement(xmlNode->Name());

	if (element == nullptr)
	{
		return nullptr;
	}

	element->setFontPath(_defaultFontPath);
	if (!element->load(xmlNode, parentSize))
	{
		return nullptr;
	}
	auto pWidget = element->getWidget();
	if (pWidget)
	{
		UIShaderHelper::loadShader(pWidget);
	}
	delete element;

	return pWidget;
}

bool UIProxy::loadWidget(CtrlWidget* pLayout, tinyxml2::XMLElement* xmlNode)
{
	if (pLayout == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	CtrlWidget* childItem = nullptr;
	tinyxml2::XMLElement* childNode = xmlNode;
	while (childNode)
	{
		childItem = initWidget(childNode, pLayout->getSize());
		if (childItem)
		{
			pLayout->addWidget(childItem);
			if (childNode->FirstChild())
			{
				loadWidget(childItem, childNode->FirstChildElement());
			}
		}
		childNode = childNode->NextSiblingElement();
	}

	return true;
}

CtrlWidget* UIProxy::loadRoot(tinyxml2::XMLElement* xmlNode, const math::Size& size)
{
	if (xmlNode == nullptr)
	{
		return nullptr;
	}

	loadInfo(xmlNode);
	loadTextures(xmlNode);

	tinyxml2::XMLElement* firstChild = xmlNode->FirstChildElement("Layout");
	if (firstChild == nullptr)
	{
		return nullptr;
	}

	CtrlWidget* pWidget = initWidget(firstChild, size);
	if (pWidget == nullptr)
	{// ¿Õ½Úµã
		return nullptr;
	}
	loadWidget(pWidget, firstChild->FirstChildElement());

	return pWidget;
}

void ui::UIProxy::loadInfo(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == nullptr)
	{
		return;
	}
	int width = xmlNode->IntAttribute(LAYOUT_SIZE_WIDTH);
	int height = xmlNode->IntAttribute(LAYOUT_SIZE_HEIGHT);

	_designSize.setWidth(width);
	_designSize.setHeight(height);

	_designDirection = (LayoutDirection)xmlNode->IntAttribute(LAYOUT_DIRECTION);
	if (xmlNode->Attribute(LAYOUT_FONT_PATH))
	{
		_defaultFontPath = xmlNode->Attribute(LAYOUT_FONT_PATH);
	}
}

void ui::UIProxy::loadTextures(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == nullptr)
	{
		return;
	}
	tinyxml2::XMLElement* pTexture = xmlNode->FirstChildElement("Texture");
	if (pTexture == nullptr)
	{
		return;
	}

	tool::TexturePacker texPacker;
	auto pChild = pTexture->FirstChildElement();
	while (pChild)
	{
		std::string type;
		std::string altas;
		std::string image;
		if (pChild->Attribute(TEXTURE_TYPE)) type = pChild->Attribute(TEXTURE_TYPE);
		if (pChild->Attribute(TEXTURE_ATLAS)) altas = pChild->Attribute(TEXTURE_ATLAS);
		if (pChild->Attribute(TEXTURE_IMAGE)) image = pChild->Attribute(TEXTURE_IMAGE);
		if (type == TEXTURE_TYPE_IMAGE)
		{
			G_TEXTURE_CACHE->createTexture2D(image);
		}
		else if (type == TEXTURE_TYPE_ATLAS)
		{
			texPacker.loadTextureAtlas(altas);
			G_TEXTURE_CACHE->addTexAltas(image, texPacker.getTextureAtlas());
		}

		pChild = pChild->NextSiblingElement();
	}
}

bool UIProxy::saveWidget(CtrlWidget* item, tinyxml2::XMLElement* xmlNode)
{
	if (item == nullptr || xmlNode == nullptr)
	{
		return false;
	}

	std::string name = getLayoutItemName(item);
	if (name.empty())
	{
		return false;
	}

	IElement* pElement = getElement(name);
	if (pElement == nullptr)
	{
		return false;
	}

	pElement->setLayoutItem(getLayoutItem(item));
	pElement->setWidget(item);

	pElement->save(xmlNode);

	WidgetLoader* pLoader = pElement->as<WidgetLoader>();
	if (pLoader == nullptr)
	{
		return true;
	}

	if (!item->is<CtrlWidget>()) return true;

	std::vector<render::Node*> children;

	if (!getVisibleChildren(item, children))
	{
		return true;
	}

	auto iter = children.begin();
	while (iter != children.end())
	{
		tinyxml2::XMLElement* pChildNode = nullptr;

		auto pWidget = dynamic_cast<CtrlWidget*>(*iter);
		if (pWidget == nullptr)
		{
			iter++;
			continue;
		}
		std::string wName = getLayoutItemName(pWidget);
		if (wName.empty())
		{
			iter++;
			continue;
		}
		pChildNode = xmlNode->GetDocument()->NewElement(wName.c_str());

		this->saveWidget(pWidget, pChildNode);

		xmlNode->InsertEndChild(pChildNode);
		iter++;
	}

	return true;
}

bool UIProxy::saveRoot(CtrlWidget* layout, tinyxml2::XMLDocument* document)
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
	return saveWidget(layout, pChildNode);
}
