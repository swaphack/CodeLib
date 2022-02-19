#include "ImageAtlasPacker.h"
#include "Document/XmlHelper.h"
#include "algorithm.h"

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

void tool::ImageAtlasPacker::setAtlas(const std::string& imgFilePath, const std::string& atlasFilePath)
{
	_textureAtlas.setAtlasPath(atlasFilePath);
	_textureAtlas.setImagePath(imgFilePath);
}

const sys::ImageTextureAtlas& tool::ImageAtlasPacker::getTextureAtlas() const
{
	return _textureAtlas;
}

sys::ImageTextureAtlas& tool::ImageAtlasPacker::getTextureAtlas()
{
	return _textureAtlas;
}

void tool::ImageAtlasPacker::loadTextureAtlas(const std::string& imageFilePath, const std::string& atlasFilePath)
{
	_textureAtlas.removeAllChips();

	XmlHelper helper;
	if (!helper.loadFile(atlasFilePath))
	{
		return;
	}
	std::map<std::string, std::string> attributes;
	helper.getRootAttributes(attributes);
	if (attributes.size() > 0)
	{
		auto it = attributes.find("imagePath");
		if (it != attributes.end()) _textureAtlas.setImagePath(it->second.c_str());
	}

	helper.foreach([this](tinyxml2::XMLElement* element) {
		if (element == nullptr) return;
		sys::ImageTextureChip chip;
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

void tool::ImageAtlasPacker::saveTextureAtlas(const std::string& atlasFilePath)
{
	XmlHelper helper;

	std::map<std::string, std::string> attributes;
	attributes["imagePath"] = _textureAtlas.getImagePath();
	helper.setRootAttributes(attributes);

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
	helper.saveTo(atlasFilePath);
}

void tool::ImageAtlasPacker::saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::ImageDetail*>& mapDetails)
{
	int id = 0;
	std::map<int, std::string> ids;

	alg::space::Bin2D bin;
	bin.setAutoRotate(isAutoRotate());
	bin.setSize(_size.getWidth(), _size.getHeight());
	for (const auto& item : mapDetails)
	{
		bin.addItem(id, item.second->getWidth(), item.second->getHeight());
		ids[id] = item.first;
		id++;
	}

	std::vector<alg::space::Bin2D::Item> items;
	if (!bin.pack(items)) return;

	sys::ImageDataFormat format = sys::ImageDataFormat::RGBA;
	int unitSize = sys::ImageDetail::getUnitSize(format);

	sys::MultiStream multiStream;
	multiStream.initSteam(unitSize * _size.getWidth(), _size.getHeight());

	_textureAtlas.removeAllChips();
	for (const auto& item : items)
	{
		std::string name = ids[item.id];
		auto it = mapDetails.find(name);
		if (it == mapDetails.end()) continue;

		auto pDetail = it->second;
		if (pDetail == nullptr) continue;

		_textureAtlas.addChip(sys::File::getFileName(name), item.width, item.height, item.x, item.y, item.rotate);

		pDetail->expandFormat();
		if (item.rotate) pDetail->rotate90();

		if (isReverseY())
		{
			multiStream.writeBlockWithReverseY(
				unitSize * item.x, item.y,
				pDetail->getUnitSize() * item.width, item.height,
				(const char*)pDetail->getPixels());
		}
		else
		{
			multiStream.writeBlock(
				unitSize * item.x, item.y,
				pDetail->getUnitSize() * item.width, item.height,
				(const char*)pDetail->getPixels());
		}

	}

	saveTextureAtlas(atlasFilePath);
	saveImage(imgFilePath, (uint8_t*)multiStream.getData(), format);
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
		if (pDetail)
		{
			mapDetails[item] = pDetail;
		}
	}

	for (const auto& item : files)
	{
		auto pDetail = sys::ResourceLoader::loadImage<sys::ImagePNG>(item);
		if (pDetail)
		{
			mapDetails[item] = pDetail;
		}
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
		SAFE_DELETE(item.second);
	}

	return true;
}
