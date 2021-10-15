#include "TexturePacker.h"
#include "algorithm.h"
#include "Document/XmlHelper.h"

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

const sys::TextureAtlas& tool::TexturePacker::getTextureAtlas() const
{
	return _textureAtlas;
}

void tool::TexturePacker::loadTextureAtlas(const std::string& altasFilePath)
{
	_textureAtlas.removeAllChips();
	_textureAtlas.setAltasPath(altasFilePath);

	XmlHelper helper;
	if (!helper.loadFile(altasFilePath))
	{
		return;
	}
	helper.foreach([this](tinyxml2::XMLElement* element) {
		if (element == nullptr) return;
		sys::TextureChip chip;
		chip.name = element->Name();
		auto pChild = element->FirstChildElement("name");
		if (pChild && pChild->GetText()) chip.name = pChild->GetText();
		pChild = element->FirstChildElement("width");
		if (pChild && pChild->GetText()) chip.width = atoi(pChild->GetText());
		pChild = element->FirstChildElement("height");
		if (pChild && pChild->GetText()) chip.height = atoi(pChild->GetText());
		pChild = element->FirstChildElement("x");
		if (pChild && pChild->GetText()) chip.x = atoi(pChild->GetText());
		pChild = element->FirstChildElement("y");
		if (pChild && pChild->GetText()) chip.y = atoi(pChild->GetText());
		pChild = element->FirstChildElement("rotate");
		if (pChild && pChild->GetText()) chip.rotate = atoi(pChild->GetText());
		_textureAtlas.addChip(chip);
	});
}

void tool::TexturePacker::saveTextureAtlas(const std::string& altasFilePath)
{
	_textureAtlas.setAltasPath(altasFilePath);

	XmlHelper helper;
	for (const auto& item : _textureAtlas.getAllChips())
	{
		std::vector<std::pair<std::string, std::string>> values;
		values.push_back(std::make_pair("name", item.first));
		values.push_back(std::make_pair("width", getCString("%d", item.second.width)));
		values.push_back(std::make_pair("height", getCString("%d", item.second.height)));
		values.push_back(std::make_pair("x", getCString("%d", item.second.x)));
		values.push_back(std::make_pair("y", getCString("%d", item.second.y)));
		if (item.second.rotate)values.push_back(std::make_pair("rotate", getCString("%d", (int)item.second.rotate)));
		helper.appendElementWithChildren("item", values);
	}
	helper.saveTo(altasFilePath);
}

bool tool::TexturePacker::packPNG(const std::string& imgFilePath, const std::string& altasFilePath)
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

	_textureAtlas.removeAllChips();
	int width = 0;
	int height = 0;
	for (const auto& item : items)
	{
		std::string name = ids[item.id];
		_textureAtlas.addChip(sys::File::getFileName(name), item.width, item.height, item.x, item.y, item.rotate);

		auto pDetail = mapDetails[name];
		if (pDetail)
		{
			width = item.width;
			height = item.height;

			pDetail->expandFormat();
			if (item.rotate)
			{
				pDetail->rotate90();
			}
			multiStream.writeBlockWithReverseY(4 * item.x, item.y,
				pDetail->getUnitSize() * width, height,
				(const char*)pDetail->getPixels());
		}
	}	
	saveTextureAtlas(altasFilePath);

	sys::ImageDetail detail;
	detail.setDataFormat(sys::ImageDataFormat::RGBA);
	detail.setPixels((uint8_t*)multiStream.getData(), _size.getWidth(), _size.getHeight(), 4);
	sys::ImageHelper::saveToPNG(detail, imgFilePath);
	for (auto& item : mapDetails)
	{
		SAFE_RELEASE(item.second);
	}

	return true;
}
