#include "DirectoryPanel.h"

void ue::DirDetail::setRoot(const std::string& root)
{
	name = root;

	sys::Directory dir;
	dir.setRoot(root);

	files = dir.getFiles();

	while (!dir.getSubDirs().empty())
	{
		for (const auto& item : dir.getSubDirs())
		{
			DirDetail subDir;
			subDir.setRoot(item);
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
	int a = 1;
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
	_dirDetail.clear();

	_dirDetail.setRoot(root);

	this->updateDirectoryPanel();
}

void ue::DirectoryPanel::updateDirectoryPanel()
{

}

