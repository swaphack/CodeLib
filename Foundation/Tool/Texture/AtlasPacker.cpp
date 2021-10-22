#include "AtlasPacker.h"
#include "Document/XmlHelper.h"
#include "algorithm.h"

tool::AtlasPacker::AtlasPacker()
{
}

tool::AtlasPacker::~AtlasPacker()
{
}

void tool::AtlasPacker::setSize(int width, int height)
{
	_size.setWidth(width);
	_size.setHeight(height);
}

int tool::AtlasPacker::getWidth() const
{
	return _size.getWidth();
}

int tool::AtlasPacker::getHeight() const
{
	return _size.getHeight();
}

void tool::AtlasPacker::setReverseY(bool reverse)
{
	_reverseY = reverse;
}

bool tool::AtlasPacker::isReverseY() const
{
	return _reverseY;
}

const sys::TextureAtlas& tool::AtlasPacker::getTextureAtlas() const
{
	return _textureAtlas;
}

void tool::AtlasPacker::loadTextureAtlas(const std::string& atlasFilePath)
{
	_textureAtlas.removeAllChips();
	_textureAtlas.setAtlasPath(atlasFilePath);

	XmlHelper helper;
	if (!helper.loadFile(atlasFilePath))
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

void tool::AtlasPacker::saveTextureAtlas(const std::string& atlasFilePath)
{
	_textureAtlas.setAtlasPath(atlasFilePath);

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
	helper.saveTo(atlasFilePath);
}

void tool::AtlasPacker::saveImage(const std::string& imgFilePath, uint8_t* data, sys::ImageDataFormat format)
{
	if (imgFilePath.empty() || data == nullptr
		|| _size.getWidth() == 0 || _size.getHeight() == 0) return;

	int unitSize = sys::ImageDetail::getUnitSize(format);
	sys::ImageDetail detail;
	detail.setDataFormat(format);
	detail.setPixels((uint8_t*)data, _size.getWidth(), _size.getHeight(), unitSize);
	sys::ImageHelper::saveToPNG(detail, imgFilePath);
}

void tool::AtlasPacker::saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::ImageDetail*>& mapDetails)
{
	int id = 0;	
	std::map<int, std::string> ids;

	alg::Bin2D bin;
	bin.setSize(_size.getWidth(), _size.getHeight());
	for (const auto& item : mapDetails)
	{
		bin.addItem(id, item.second->getWidth(), item.second->getHeight());
		ids[id] = item.first;
		id++;
	}

	std::vector<alg::Bin2D::Item> items;
	if (!bin.pack(items)) return;

	sys::ImageDataFormat format = sys::ImageDataFormat::RGBA;
	int unitSize = sys::ImageDetail::getUnitSize(format);

	sys::MultiStream multiStream;
	multiStream.initSteam(unitSize * _size.getWidth(), _size.getHeight());

	_textureAtlas.removeAllChips();
	for (const auto& item : items)
	{
		std::string name = ids[item.id];
		_textureAtlas.addChip(sys::File::getFileName(name), item.width, item.height, item.x, item.y, item.rotate);

		auto it = mapDetails.find(name);
		if (it == mapDetails.end()) continue;

		auto pDetail = it->second;
		if (pDetail == nullptr) continue;

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
