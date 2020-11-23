#include "DirectoryPanel.h"
#include "render.h"

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


ue::DirectoryPanel::DirectoryPanel()
{

}

ue::DirectoryPanel::~DirectoryPanel()
{
}

bool ue::DirectoryPanel::init()
{
	if (!Panel::init())
	{
		return false;
	}
	return true;
}

void ue::DirectoryPanel::initUI()
{
	this->setDirectory("H:/Github/CodeLib/Sample/UIEditor/Resource/");
}

void ue::DirectoryPanel::initEvent()
{
}

void ue::DirectoryPanel::initText()
{

}

void ue::DirectoryPanel::setDirectory(const std::string& root)
{
	_root = root;

	_dirDetail.setRoot(root);

	this->updateRootPanel();
}

void ue::DirectoryPanel::updateRootPanel()
{
	this->getLayout()->removeAllItems();
	this->getLayout()->getWidget()->removeAllWidgets();

	_top = 0;
	this->updateRootList(this->getLayout(), _dirDetail);

	this->getLayout()->autoResize();
}

void ue::DirectoryPanel::updateRootList(ui::Layout* layout, const DirDetail& detail)
{
	if (layout == nullptr)
	{
		return;
	}

	if (detail.files.size() == 0 && detail.subDirs.size() == 0)
	{
		return;
	}

	auto pItem = createRootItem(_top, CONST_ITEM_HEIGHT, true, detail.name, detail.fullpath);
	if (pItem)
	{
		layout->addItemWithWidget(pItem);
		_top += CONST_ITEM_HEIGHT + CONST_OFFSET_Y;
	}
	
	// 文件
	if (!isDirFolded(detail.fullpath))
	{
		// 子目录
		for (const auto& subDir : detail.subDirs)
		{
			updateRootList(layout, subDir);
		}

		for (auto item : detail.files)
		{
			auto pItem = createRootItem(_top, CONST_ITEM_HEIGHT, false, item, detail.fullpath + "/" + item);
			if (pItem)
			{
				layout->addItemWithWidget(pItem);
				_top += CONST_ITEM_HEIGHT + CONST_OFFSET_Y;
			}
		}
	}
}

ui::LayoutItem* ue::DirectoryPanel::createDirItem(int top, int height, const std::string& name, const std::string& fullpath)
{
	auto pItem = createIteam<render::CtrlButton>();
	if (pItem == nullptr)
	{
		return nullptr;
	}

	pItem->getMarginState().Left = true;
	pItem->getMarginState().Right = true;
	pItem->getMarginState().Top = true;

	pItem->getMargin().setLeft(sys::NumberType::Fixed, 0);
	pItem->getMargin().setRight(sys::NumberType::Fixed, 0);
	pItem->getMargin().setTop(sys::NumberType::Fixed, top);


	pItem->getSize().setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	pItem->getSize().setHeight(sys::NumberType::Fixed, height);

	auto pWidget = pItem->getCastWidget<render::CtrlButton>();
	if (pWidget)
	{
		pWidget->setNormalImage("Default/Image/dir_bg.png");
		pWidget->setAnchorPoint(0.5f, 0.5f);
		pWidget->setTextColor(sys::Color3B(255, 255, 255));
		pWidget->setFontSize(24);
		pWidget->setFontPath("Default/Font/font_3.ttf");
		pWidget->setString(name);
	}
	return pItem;
}

ui::LayoutItem* ue::DirectoryPanel::createFileItem(int top, int height, const std::string& name)
{
	auto pItem = createIteam<render::CtrlButton>();
	if (pItem == nullptr)
	{
		return nullptr;
	}

	pItem->getMarginState().Left = true;
	pItem->getMarginState().Right = true;
	pItem->getMarginState().Top = true;

	pItem->getMargin().setLeft(sys::NumberType::Fixed, 0);
	pItem->getMargin().setRight(sys::NumberType::Fixed, 0);
	pItem->getMargin().setTop(sys::NumberType::Fixed, top);

	pItem->getSize().setWidth(sys::NumberType::Percent, ONE_HUNDRED);
	pItem->getSize().setHeight(sys::NumberType::Fixed, height);

	auto pWidget = pItem->getCastWidget<render::CtrlButton>();
	if (pWidget)
	{
		pWidget->setNormalImage("Default/Image/file_bg.png");
		pWidget->setAnchorPoint(0.5f, 0.5f);
		pWidget->setTextColor(sys::Color3B(0, 0, 0));
		pWidget->setFontSize(24);
		pWidget->setFontPath("Default/Font/font_3.ttf");
		pWidget->setString(name);
	}
	
	return pItem;
}

ui::LayoutItem* ue::DirectoryPanel::createRootItem(int top, int height, bool isDir, const std::string& name, const std::string& fullpath)
{
	ui::LayoutItem* item = nullptr;
	auto it = _dirItems.find(fullpath);
	if (it != _dirItems.end())
	{
		item = it->second;
	}
	if (item == nullptr)
	{
		if (isDir)
		{
			item = createDirItem(top, height, name, fullpath);
		}
		else
		{
			item = createFileItem(top, height, name);
		}
		if (item)
		{
			SAFE_RETAIN(item);
			SAFE_RETAIN(item->getWidget());
			_dirItems.insert(std::make_pair(fullpath, item));
		}
	}
	item->getMargin().setTop(sys::NumberType::Fixed, top);
	if (isDir)
	{
		item->getWidget()->removeAllClickFuncs();
		item->getWidget()->addClickFunc([this, fullpath](CtrlWidget*) {
			this->onChangeFoldState(fullpath);
			this->updateRootPanel();
		});
	}

	return item;
}

void ue::DirectoryPanel::onChangeFoldState(const std::string& name)
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

bool ue::DirectoryPanel::isDirFolded(const std::string& name)
{
	auto it = _dirFoldInfo.find(name);

	if (it == _dirFoldInfo.end())
	{
		return false;
	}

	return it->second;
}

