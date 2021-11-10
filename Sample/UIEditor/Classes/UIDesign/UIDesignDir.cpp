#include "UIDesignDir.h"
#include "render.h"
#include "Panel/PanelEvent.h"

ue::UIDesignDir::UIDesignDir()
{

}

ue::UIDesignDir::~UIDesignDir()
{
}

bool ue::UIDesignDir::init()
{
	if (!Panel::init())
	{
		return false;
	}
	return true;
}

int ue::UIDesignDir::getDataCount()
{
	int nCount = _simpleDirInfo.size();
	nCount = 100;
	return nCount;
}

math::Size ue::UIDesignDir::getDataSize(int index)
{
	return math::Size(this->getWidth(), CONST_ITEM_HEIGHT);
}

ui::CtrlWidget* ue::UIDesignDir::getDataCell(int index)
{
	if (index < 0 || index >= _simpleDirInfo.size())
	{
		return nullptr;
	}
	int tempCount = 0;
	bool bFile = false;
	const SimpleDirInfo& detail = _simpleDirInfo.at(index);
	if (detail.type == 1)
	{
		return createFileItem(CONST_ITEM_HEIGHT, detail.name, detail.fullpath);
	}
	else
	{
		return createDirItem(CONST_ITEM_HEIGHT, detail.name, detail.fullpath);
	}
}

void ue::UIDesignDir::initUI()
{
	m_pRootWidget->findWidgetByName("directory", _tableView);
	if (_tableView)
	{
		_tableView->setTableData(this);
	}
	this->setDirectory("H:/Github/CodeLib/Sample/UIEditor/Resource/");
}

void ue::UIDesignDir::initEvent()
{
}

void ue::UIDesignDir::initText()
{

}

void ue::UIDesignDir::setDirectory(const std::string& root)
{
	_root = root;

	DirList::getAllFiles(root, _simpleDirInfo);

	this->updateRootPanel(true);
}

void ue::UIDesignDir::updateRootPanel(bool cleanFold)
{
	if (cleanFold)
		_dirFoldInfo.clear();

	if (_tableView)
	{
		_tableView->reload();
	}
	//this->updateRootList(_listview, _dirDetail);
}

void ue::UIDesignDir::updateRootList(ui::CtrlListView* layout, const DirDetail& detail, int layer)
{
	if (layout == nullptr)
	{
		return;
	}

	if (detail.files.size() == 0 && detail.subDirs.size() == 0)
	{
		return;
	}

	bool isFolded = isDirFolded(detail.fullpath);

	std::string fullpath = std::string(layer + 1, ' ') + detail.name;

	auto pItem = createDirItem(CONST_ITEM_HEIGHT, fullpath, detail.fullpath);
	if (pItem)
	{
		pItem->setSelectState(isFolded);
		layout->addItem(pItem);
	}

	// 文件
	if (!isFolded)
	{
		// 子目录
		for (const auto& subDir : detail.subDirs)
		{
			updateRootList(layout, subDir, layer + 1);
		}

		for (auto item : detail.files)
		{
			auto pItem = createFileItem(CONST_ITEM_HEIGHT, std::string(layer + 2, ' ') + item, detail.fullpath + "/" + item);
			if (pItem)
			{
				layout->addItem(pItem);
			}
		}
	}
}

ui::CtrlButton* ue::UIDesignDir::createDirItem(int height, const std::string& name, const std::string& fullpath)
{
	auto pWidget = createWidget<ui::CtrlButton>();
	if (pWidget == nullptr)
	{
		return nullptr;
	}

	auto pItem = pWidget->getLayoutItem();
	pItem->setMarginState(false, true, false, true);

	//pItem->setMargin(2, 2, 2, 2);
	pItem->getSize().setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	pItem->getSize().setHeight(sys::NumberType::Fixed, height);

	if (pWidget)
	{
		pWidget->setNormalImage("Default/Atlas/ui.atlas[dir_bg.png]");
		pWidget->setSelectedImage("Default/Atlas/ui.atlas[dir_bg_2.png]");
		pWidget->setTextColor(phy::Color3B(255, 255, 255));
		pWidget->setFontSize(CONST_ITEM_HEIGHT);
		pWidget->setFontImagePath(G_UIPROXY->getFontImagePath());
		pWidget->setFontPath(G_UIPROXY->getFontPath());
		pWidget->setString(name);
		pWidget->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
		pWidget->setTextVerticalAlignment(sys::VerticalAlignment::BOTTOM);
		pWidget->addClickFunc([this, fullpath](CtrlWidget*) {
			this->onChangeFoldState(fullpath);
			this->updateRootPanel(false);
			});
	}
	return pWidget;
}

ui::CtrlButton* ue::UIDesignDir::createFileItem(int height, const std::string& name, const std::string& fullpath)
{
	auto pWidget = createWidget<ui::CtrlButton>();
	if (pWidget == nullptr)
	{
		return nullptr;
	}

	auto pItem = pWidget->getLayoutItem();
	pItem->setMarginState(false, true, false, true);

	pItem->getSize().setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	pItem->getSize().setHeight(sys::NumberType::Fixed, height);

	if (pWidget)
	{
		pWidget->setNormalImage("Default/Atlas/ui.atlas[file_bg.png]");
		pWidget->setSelectedImage("Default/Atlas/ui.atlas[file_bg_2.png]");
		pWidget->setTextColor(phy::Color3B(0, 0, 0));
		pWidget->setFontSize(CONST_ITEM_HEIGHT);
		pWidget->setFontImagePath(G_UIPROXY->getFontImagePath());
		pWidget->setFontPath(G_UIPROXY->getFontPath());
		pWidget->setString(name);
		pWidget->setTextHorizontalAlignment(sys::HorizontalAlignment::LEFT);
		pWidget->setTextVerticalAlignment(sys::VerticalAlignment::BOTTOM);
		pWidget->addClickFunc([this, fullpath](CtrlWidget*) {
			G_PANELEVT->setSelectFile(fullpath);
			});
	}

	return pWidget;
}

int ue::UIDesignDir::getTotalDirCount(const DirDetail& detail)
{
	int count = 1;

	if (detail.files.size() == 0 && detail.subDirs.size() == 0)
	{
		return count;
	}
	for (const auto& item : detail.subDirs)
	{
		if (isDirFolded(item.fullpath)) continue;
		count += getTotalDirCount(item);
	}
	count += detail.files.size();
	return count;
}

ue::DirDetail ue::UIDesignDir::getDirDetail(const DirDetail& detail, int index, int tempCount, bool& bFile)
{
	DirDetail tempDetail;
	tempCount += 1;
	if (index == tempCount - 1)
	{
		bFile = false;
		return detail;
	}
	if (detail.files.size() == 0 && detail.subDirs.size() == 0)
	{
		bFile = false;
		return tempDetail;
	}
	for (const auto& item : detail.subDirs)
	{
		if (isDirFolded(item.fullpath)) continue;
		auto result = getDirDetail(item, index, tempCount, bFile);
		if (result.name != "") return result;
	}
	if (index < tempCount + detail.files.size())
	{
		int offset = index - tempCount;
		tempDetail.name = detail.files[offset];
		tempDetail.fullpath = detail.fullpath +"/" + detail.name;
		bFile = true;
		return tempDetail;
	}
	tempCount += detail.files.size();
	return tempDetail;
}

void ue::UIDesignDir::onChangeFoldState(const std::string& name)
{
	auto it = _dirFoldInfo.find(name);
	if (it != _dirFoldInfo.end())
	{
		_dirFoldInfo[name] = !_dirFoldInfo[name];
	}
	else
	{
		_dirFoldInfo.insert(std::make_pair(name, true));
	}
}

bool ue::UIDesignDir::isDirFolded(const std::string& name)
{
	auto it = _dirFoldInfo.find(name);

	if (it == _dirFoldInfo.end())
	{
		return false;
	}

	return it->second;
}

