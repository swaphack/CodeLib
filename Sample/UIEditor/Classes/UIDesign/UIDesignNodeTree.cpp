#include "UIDesignNodeTree.h"
#include "Panel/PanelEvent.h"

ue::UIDesignNodeTree::UIDesignNodeTree()
{
	G_PANELEVT->setNodeTreePanel(this);
}

ue::UIDesignNodeTree::~UIDesignNodeTree()
{
	G_PANELEVT->setNodeTreePanel(nullptr);
}

bool ue::UIDesignNodeTree::init()
{
	if (!Panel::init())
	{
		return false;
	}
	G_PANELEVT->addEventListener(PANEL_SELECT_ROOT, this, [this](const sys::Event* evt) {
		if (evt)
		{
			render::Node* root = (render::Node*)evt->getUserData();
			this->setNode(root);
		}
	});
	return true;
}

void ue::UIDesignNodeTree::initUI()
{
	m_pRootWidget->findWidgetByName("root", _listview);
}

void ue::UIDesignNodeTree::initEvent()
{
}

void ue::UIDesignNodeTree::initText()
{
}

void ue::UIDesignNodeTree::setNode(Node* pNode)
{
	if (pNode == nullptr) return;
	if (pNode->getName() == "")
	{
		pNode->setName("Root");
	}
	_rootNode = pNode;

	this->updateRootPanel(true);
}

void ue::UIDesignNodeTree::updateRootPanel(bool cleanFold)
{
	if (_listview == nullptr) return;

	_listview->removeAllItems();
	if (cleanFold)
		_dirFoldInfo.clear();

	if (_rootNode == nullptr) return;

	int layer = 0;
	updateRootList(_listview, _rootNode, layer);
}

void ue::UIDesignNodeTree::updateRootList(ui::CtrlListView* layout, const Node* pNode, int layer)
{
	if (layout == nullptr || pNode == nullptr) return;

	bool isFolded = isDirFolded(pNode);

	std::vector<render::Node*> children;

	if (!ui::UIProxy::getVisibleChildren(pNode, children))
	{
		return;
	}

	int nChildrenCount = children.size();

	std::string name = std::string(layer + 1, ' ') + pNode->getName();

	if (nChildrenCount > 0)
	{
		auto pItem = createHasChildrenNode(CONST_ITEM_HEIGHT, name, pNode);
		if (pItem)
		{
			pItem->setSelectState(isFolded);
			layout->addItem(pItem);
		}
	}
	else
	{
		auto pItem = createHasChildrenNode(CONST_ITEM_HEIGHT, name, pNode);
		if (pItem)
		{
			layout->addItem(pItem);
		}
	}
	// нд╪Ч
	if (!isFolded)
	{
		for (size_t i = 0; i < nChildrenCount; i++)
		{
			auto pChild = children.at(i);
			if (pChild)
			{
				updateRootList(layout, pChild, layer + 1);
			}
		}
	}
	
}

void ue::UIDesignNodeTree::onChangeFoldState(const render::Node* node)
{
	if (node == nullptr) return;

	auto pNode = (render::Node*)node;

	auto it = _dirFoldInfo.find(pNode);
	if (it != _dirFoldInfo.end())
	{
		_dirFoldInfo[pNode] = !_dirFoldInfo[pNode];
	}
	else
	{
		_dirFoldInfo.insert(std::make_pair(pNode, true));
	}
}

bool ue::UIDesignNodeTree::isDirFolded(const render::Node* node)
{
	if (true) return false;

	if (node == nullptr) return false;

	auto pNode = (render::Node*)node;

	auto it = _dirFoldInfo.find(pNode);

	if (it == _dirFoldInfo.end())
	{
		return false;
	}

	return it->second;
}

ui::CtrlButton* ue::UIDesignNodeTree::createHasChildrenNode(int height, const std::string& name, const render::Node* node)
{
	auto pWidget = createWidget<ui::CtrlButton>();
	if (pWidget == nullptr)
	{
		return nullptr;
	}

	auto pItem = pWidget->getLayoutItem();

	pItem->setMargin(2, 2, 2, 2);
	pItem->getSize().setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	pItem->getSize().setHeight(sys::NumberType::Fixed, height);

	if (pWidget)
	{
		pWidget->setNormalImage("Default/Atlas/ui.png[dir_bg.png]");
		pWidget->setSelectedImage("Default/Atlas/ui.png[dir_bg_2.png]");
		pWidget->setTextColor(phy::Color3B(255, 255, 255));
		pWidget->setFontSize(CONST_ITEM_HEIGHT);
		pWidget->setFontImagePath(G_UIPROXY->getFontImagePath());
		pWidget->setFontPath(G_UIPROXY->getFontPath());
		pWidget->setString(name);
		pWidget->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
		pWidget->setTextVerticalAlignment(sys::VerticalAlignment::BOTTOM);
		pWidget->addClickFunc([this, node](CtrlWidget*) {
			std::vector<int> vecIndex;
			auto pTemp = node;
			while (pTemp != _rootNode)
			{
				int index = pTemp->getParent()->indexOfChild(pTemp);
				pTemp = pTemp->getParent();
				vecIndex.push_back(index);
			}
			std::reverse(vecIndex.begin(), vecIndex.end());
			G_PANELEVT->setSelectTreeNode(vecIndex);

			this->onChangeFoldState(node);
			this->updateRootPanel();
		});
	}
	return pWidget;
}

ui::CtrlButton* ue::UIDesignNodeTree::createNoChildrenNode(int height, const std::string& name, const render::Node* node)
{
	auto pWidget = createWidget<ui::CtrlButton>();
	if (pWidget == nullptr)
	{
		return nullptr;
	}

	auto pItem = pWidget->getLayoutItem();

	pItem->setMargin(2, 2, 2, 2);
	pItem->getSize().setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	pItem->getSize().setHeight(sys::NumberType::Fixed, height);

	if (pWidget)
	{
		pWidget->setNormalImage("Default/Atlas/ui.png[file_bg.png]");
		pWidget->setSelectedImage("Default/Atlas/ui.png[file_bg_2.png]");
		pWidget->setTextColor(phy::Color3B(0, 0, 0));
		pWidget->setFontSize(CONST_ITEM_HEIGHT);
		pWidget->setFontImagePath(G_UIPROXY->getFontImagePath());
		pWidget->setFontPath(G_UIPROXY->getFontPath());
		pWidget->setString(name);
		pWidget->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
		pWidget->setTextVerticalAlignment(sys::VerticalAlignment::BOTTOM);

		pWidget->addClickFunc([this, node](CtrlWidget*) {
			std::vector<int> vecIndex;
			auto pTemp = node;
			while (pTemp != _rootNode)
			{
				int index = pTemp->getParent()->indexOfChild(pTemp);
				pTemp = pTemp->getParent();
				vecIndex.push_back(index);
			}
			std::reverse(vecIndex.begin(), vecIndex.end());
			G_PANELEVT->setSelectTreeNode(vecIndex);
		});
	}

	return pWidget;
}


