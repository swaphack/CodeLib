#include "UIDesignDirectory.h"
#include "render.h"
#include "Panel/PanelEvent.h"

void ue::DirDetail::setRoot(const std::string& root)
{
	this->clear();

	fullpath = root;

	name = sys::Directory::getDirName(root);

	sys::Directory dir;
	dir.setRoot(root);

	files = dir.getFiles();

	if(!dir.getSubDirs().empty())
	{
		for (const auto& item : dir.getSubDirs())
		{
			DirDetail subDir;
			subDir.setRoot(root + item);
			subDirs.push_back(subDir);
		}
	}
}

void ue::DirDetail::clear()
{
	subDirs.clear();
	files.clear();
}


ue::UIDesignDirectory::UIDesignDirectory()
{

}

ue::UIDesignDirectory::~UIDesignDirectory()
{
}

bool ue::UIDesignDirectory::init()
{
	if (!Panel::init())
	{
		return false;
	}
	return true;
}

void ue::UIDesignDirectory::initUI()
{
	m_pRootWidget->findWidgetByName("directory", _listview);
	this->setDirectory("H:/Github/CodeLib/Sample/UIEditor/Resource/");
}

void ue::UIDesignDirectory::initEvent()
{
}

void ue::UIDesignDirectory::initText()
{

}

void ue::UIDesignDirectory::setDirectory(const std::string& root)
{
	_root = root;

	_dirDetail.setRoot(root);

	this->updateRootPanel(true);
}

void ue::UIDesignDirectory::updateRootPanel(bool cleanFold)
{
	_listview->removeAllItems();
	if (cleanFold)
		_dirFoldInfo.clear();

	this->updateRootList(_listview, _dirDetail);
}

void ue::UIDesignDirectory::updateRootList(ui::CtrlListView* layout, const DirDetail& detail, int layer)
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

ui::CtrlButton* ue::UIDesignDirectory::createDirItem(int height, const std::string& name, const std::string& fullpath)
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
		pWidget->setNormalImage("Default/Image/dir_bg.png");
		pWidget->setSelectedImage("Default/Image/dir_bg_2.png");
		pWidget->setTextColor(phy::Color3B(255, 255, 255));
		pWidget->setFontSize(CONST_ITEM_HEIGHT);
		pWidget->setFontPath("Default/Font/font_3.ttf");
		pWidget->setString(name);
		pWidget->getTextControl()->setHorizontalAlignment(sys::HorizontalAlignment::LEFT);
		pWidget->getTextControl()->setVerticalAlignment(sys::VerticalAlignment::BOTTOM);
		pWidget->addClickFunc([this, fullpath](CtrlWidget*) {
			this->onChangeFoldState(fullpath);
			this->updateRootPanel(false);
		});
	}
	return pWidget;
}

ui::CtrlButton* ue::UIDesignDirectory::createFileItem(int height, const std::string& name, const std::string& fullpath)
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
		pWidget->setNormalImage("Default/Image/file_bg.png");
		pWidget->setSelectedImage("Default/Image/file_bg_2.png");
		pWidget->setTextColor(phy::Color3B(0, 0, 0));
		pWidget->setFontSize(CONST_ITEM_HEIGHT);
		pWidget->setFontPath("Default/Font/font_3.ttf");
		pWidget->setString(name);
		pWidget->getTextControl()->setHorizontalAlignment(sys::HorizontalAlignment::LEFT);
		pWidget->getTextControl()->setVerticalAlignment(sys::VerticalAlignment::BOTTOM);

		pWidget->addClickFunc([this, fullpath](CtrlWidget*) {
			G_PANELEVT->setDesignFile(fullpath);
		});
	}
	
	return pWidget;
}

void ue::UIDesignDirectory::onChangeFoldState(const std::string& name)
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

bool ue::UIDesignDirectory::isDirFolded(const std::string& name)
{
	auto it = _dirFoldInfo.find(name);

	if (it == _dirFoldInfo.end())
	{
		return false;
	}

	return it->second;
}

