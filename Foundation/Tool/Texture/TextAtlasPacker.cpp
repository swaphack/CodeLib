#include "TextAtlasPacker.h"
#include "system.h"
#include "Document/XmlHelper.h"
#include "algorithm.h"

tool::TextAtlasPacker::TextAtlasPacker()
{
}

tool::TextAtlasPacker::~TextAtlasPacker()
{
}

void tool::TextAtlasPacker::setText(const std::string& content, const std::string& fontFilePath, int fontSize)
{
    _textDefine.text = content;
    _textDefine.fontSize = fontSize;
    _textDefine.filepath = fontFilePath;
}

void tool::TextAtlasPacker::setAtlas(const std::string& imgFilePath, const std::string& atlasFilePath)
{
	_textureAtlas.setAtlasPath(atlasFilePath);
	_textureAtlas.setImagePath(imgFilePath);
}

const sys::FontTextureAtlas& tool::TextAtlasPacker::getTextureAtlas() const
{
	return _textureAtlas;
}

sys::FontTextureAtlas& tool::TextAtlasPacker::getTextureAtlas()
{
	return _textureAtlas;
}

void tool::TextAtlasPacker::loadTextureAtlas(const std::string& imageFilePath, const std::string& atlasFilePath)
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
		auto it = attributes.find("fontSize");
		if (it != attributes.end()) _textureAtlas.setFontSize(atoi(it->second.c_str()));
		it = attributes.find("lineHeight");
		if (it != attributes.end()) _textureAtlas.setLineHeight(atoi(it->second.c_str()));
		it = attributes.find("imagePath");
		if (it != attributes.end()) _textureAtlas.setImagePath(it->second.c_str());
	}

	helper.foreach([this](tinyxml2::XMLElement* element) {
		if (element == nullptr) return;
		sys::FontTextureChip chip;
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
		pChild = element->FirstChildElement("advX");
		if (pChild && pChild->GetText()) chip.advX = atoi(pChild->GetText());
		pChild = element->FirstChildElement("advY");
		if (pChild && pChild->GetText()) chip.advY = atoi(pChild->GetText());
		pChild = element->FirstChildElement("deltaX");
		if (pChild && pChild->GetText()) chip.deltaX = atoi(pChild->GetText());
		pChild = element->FirstChildElement("deltaY");
		if (pChild && pChild->GetText()) chip.deltaY = atoi(pChild->GetText());
		_textureAtlas.addChip(chip);
	});
}

void tool::TextAtlasPacker::saveTextureAtlas(const std::string& atlasFilePath)
{
	XmlHelper helper;

	std::map<std::string, std::string> attributes;
	attributes["fontSize"] = getCString("%d", _textureAtlas.getFontSize());
	attributes["lineHeight"] = getCString("%d", _textureAtlas.getLineHeight());
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
		values.push_back(std::make_pair("advX", getCString("%d", item.second.advX)));
		values.push_back(std::make_pair("advY", getCString("%d", item.second.advY)));
		values.push_back(std::make_pair("deltaX", getCString("%d", item.second.deltaX)));
		values.push_back(std::make_pair("deltaY", getCString("%d", item.second.deltaY)));
		helper.appendElementWithChildren("item", values);
	}
	helper.saveTo(atlasFilePath);
}

void tool::TextAtlasPacker::saveTexAltas(const std::string& imgFilePath, const std::string& atlasFilePath, const std::map<std::string, sys::FontCharDetail*>& mapDetails)
{
	int id = 0;
	std::map<int, std::string> ids;

	alg::Bin2D bin;
	bin.setAutoRotate(isAutoRotate());
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

	float offsetY = 0;
	for (const auto& item : items)
	{
		std::string name = ids[item.id];
		auto it = mapDetails.find(name);
		if (it == mapDetails.end()) continue;

		auto pDetail = it->second;
		if (pDetail == nullptr) continue;
		
		//offsetY = _size.getHeight() - item.y;
		_textureAtlas.addChip(sys::File::getFileName(name), item.width, item.height, item.x, item.y, item.rotate,
			pDetail->getAdvanceX(), pDetail->getAdvanceY(), pDetail->getDeltaX(), pDetail->getDeltaY());
		pDetail->expandFormat();
		pDetail->flipY();
		if (item.rotate)
		{
			pDetail->rotate90();
		}

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

bool tool::TextAtlasPacker::packImage(const std::string& imgFilePath, const std::string& atlasFilePath)
{
    std::map<std::string, sys::FontCharDetail*> mapDetails;
	int lineHeight = 0;
	G_FONT_LIB->load(_textDefine, lineHeight, mapDetails);
	if (mapDetails.size() == 0) return false;

	_textureAtlas.setLineHeight(lineHeight);
	_textureAtlas.setFontSize(_textDefine.fontSize);

	saveTexAltas(imgFilePath, atlasFilePath, mapDetails);

	for (auto& item : mapDetails)
	{
		SAFE_RELEASE(item.second);
	}

	return true;
}

