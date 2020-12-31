#include "UIDesignTree.h"

ue::UIDesignTree::UIDesignTree()
{
}

ue::UIDesignTree::~UIDesignTree()
{
}

bool ue::UIDesignTree::init()
{
	return false;
}

void ue::UIDesignTree::initUI()
{
}

void ue::UIDesignTree::initEvent()
{
}

void ue::UIDesignTree::initText()
{
}

void ue::UIDesignTree::setNode(const Node* pNode)
{
}

void ue::UIDesignTree::updateRootPanel()
{
}

void ue::UIDesignTree::updateRootList(ui::CtrlListView* layout, const Node* pNode, int layer)
{
}

void ue::UIDesignTree::onChangeFoldState(const std::string& name)
{
}

bool ue::UIDesignTree::isDirFolded(const std::string& name)
{
	return false;
}

ui::CtrlButton* ue::UIDesignTree::createHasChildrenNode(int height, const std::string& name, const std::string& fullpath)
{
	return nullptr;
}

ui::CtrlButton* ue::UIDesignTree::createNoChildrenNode(int height, const std::string& name, const std::string& fullpath)
{
	return nullptr;
}
