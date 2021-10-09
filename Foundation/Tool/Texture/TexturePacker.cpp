#include "TexturePacker.h"
#include "system.h"
#include "algorithm.h"
#include "TextureAtlas.h"

tool::TexturePacker::TexturePacker()
{
}

tool::TexturePacker::~TexturePacker()
{
}

void tool::TexturePacker::setSize(int width, int height)
{
	_size.setWidth(width);
	_size.setHeight(height);
}

int tool::TexturePacker::getWidth() const
{
	return _size.getWidth();
}

int tool::TexturePacker::getHeight() const
{
	return _size.getHeight();
}

void tool::TexturePacker::addImage(const std::string& filepath)
{
	_images.insert(filepath);
}

void tool::TexturePacker::removeImage(const std::string& filepath)
{
	_images.erase(filepath);
}

void tool::TexturePacker::removeAllImages()
{
	_images.clear();
}

void tool::TexturePacker::addDirectory(const std::string& filepath)
{
	_dirs.insert(filepath);
}

void tool::TexturePacker::removeDirectory(const std::string& filepath)
{
	_dirs.erase(filepath);
}

void tool::TexturePacker::removeAllDirectories()
{
	_dirs.clear();
}

bool tool::TexturePacker::pack(const std::string& filepath)
{
	std::vector<std::string> files;
	for (const auto& item : _dirs)
	{
		sys::Directory::getAllFiles(item, files, "*.png");
	}

	std::map<std::string, sys::ImageDetail*> mapDetails;
	std::map<int, std::string> ids;
	alg::Bin2D bin;
	bin.setSize(_size.getWidth(), _size.getHeight());
	for (const auto& item : _images)
	{
		auto pDetail = sys::ResourceLoader::loadImage<sys::ImagePNG>(item);
		if (pDetail)
		{
			mapDetails[item] = pDetail;

			int id = ids.size();
			ids[id] = item;
			bin.addItem(id, pDetail->getWidth(), pDetail->getHeight());
		}
	}

	for (const auto& item : files)
	{
		auto pDetail = sys::ResourceLoader::loadImage<sys::ImagePNG>(item);
		if (pDetail)
		{
			mapDetails[item] = pDetail;

			int id = ids.size();
			ids[id] = item;
			bin.addItem(id, pDetail->getWidth(), pDetail->getHeight());
		}
	}

	std::vector<alg::Bin2D::Item> items;
	bin.pack(items);
	if (items.size() == 0)
	{
		return false;
	}
	sys::MultiStream multiStream;
	multiStream.initSteam(4 * _size.getWidth(), _size.getHeight());

	TextureAtlas altas;
	for (const auto& item : items)
	{
		std::string name = ids[item.id];
		altas.addChip(sys::File::getFileName(name), item.width, item.height, item.x, item.y, item.rotate);

		auto pDetail = mapDetails[name];
		if (pDetail)
		{
			multiStream.writeBlock(4 * item.x, item.y,
				4 * item.width, item.height,
				(const char*)pDetail->getPixels());
		}
	}	
	altas.pack(filepath + ".atlas");

	sys::ImageDetail detail;
	detail.setDataFormat(sys::ImageDataFormat::RGBA);
	detail.setPixels((uint8_t*)multiStream.getData(), _size.getWidth(), _size.getHeight(), 4);
	sys::ImageHelper::saveToPNG(detail, filepath + ".png");
	for (auto& item : mapDetails)
	{
		SAFE_RELEASE(item.second);
	}

	return true;
}
