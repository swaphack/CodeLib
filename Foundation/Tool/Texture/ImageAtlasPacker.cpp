#include "ImageAtlasPacker.h"


tool::ImageAtlasPacker::ImageAtlasPacker()
{
}

tool::ImageAtlasPacker::~ImageAtlasPacker()
{
}

void tool::ImageAtlasPacker::addImage(const std::string& filepath)
{
	_images.insert(filepath);
}

void tool::ImageAtlasPacker::removeImage(const std::string& filepath)
{
	_images.erase(filepath);
}

void tool::ImageAtlasPacker::removeAllImages()
{
	_images.clear();
}

void tool::ImageAtlasPacker::addDirectory(const std::string& filepath)
{
	_dirs.insert(filepath);
}

void tool::ImageAtlasPacker::removeDirectory(const std::string& filepath)
{
	_dirs.erase(filepath);
}

void tool::ImageAtlasPacker::removeAllDirectories()
{
	_dirs.clear();
}

void tool::ImageAtlasPacker::loadImageDetails(std::map<std::string, sys::ImageDetail*>& mapDetails, const std::string& format)
{
	std::vector<std::string> files;
	for (const auto& item : _dirs)
	{
		sys::Directory::getAllFiles(item, files, format);
	}
	for (const auto& item : _images)
	{
		auto pDetail = sys::ResourceLoader::loadImage<sys::ImagePNG>(item);
		if (pDetail) mapDetails[item] = pDetail;
	}

	for (const auto& item : files)
	{
		auto pDetail = sys::ResourceLoader::loadImage<sys::ImagePNG>(item);
		if (pDetail) mapDetails[item] = pDetail;
	}
}

bool tool::ImageAtlasPacker::packImage(const std::string& imgFilePath, const std::string& atlasFilePath)
{
	std::map<std::string, sys::ImageDetail*> mapDetails;
	loadImageDetails(mapDetails, "*.png");
	if (mapDetails.size() == 0) return false;

	saveTexAltas(imgFilePath, atlasFilePath, mapDetails);

	for (auto& item : mapDetails)
	{
		SAFE_RELEASE(item.second);
	}

	return true;
}
