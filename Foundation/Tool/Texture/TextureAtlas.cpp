#include "TextureAtlas.h"
#include "Document/XmlHelper.h"
#include "system.h"

tool::TextureAtlas::TextureAtlas()
{
}

tool::TextureAtlas::~TextureAtlas()
{
}

void tool::TextureAtlas::unpack(const std::string& filepath)
{
	_chips.clear();

	XmlHelper helper;
	if (!helper.loadFile(filepath))
	{
		return;
	}
	helper.foreach([this](tinyxml2::XMLElement* element) {
		if (element == nullptr) return;
		TextureChip& chip = _chips[element->Name()];
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
	});
}

void tool::TextureAtlas::pack(const std::string& filepath)
{
	XmlHelper helper;
	for (const auto& item : _chips)
	{
		std::map<std::string, std::string> values;
		values["name"] = item.first;
		values["width"] = getCString("%d", item.second.width);
		values["height"] = getCString("%d", item.second.height);
		values["x"] = getCString("%d", item.second.x);
		values["y"] = getCString("%d", item.second.y);
		values["rotate"] = getCString("%d", (int)item.second.rotate);
		helper.appendElementWithChildren("item", values);
	}
	helper.saveTo(filepath);
}

void tool::TextureAtlas::addChip(const std::string& name, int width, int height, int x, int y, bool rotate)
{
	TextureChip& chip = _chips[name];
	chip.name = name;
	chip.width = width;
	chip.height = height;
	chip.x = x;
	chip.y = y;
	chip.rotate = rotate;
}

void tool::TextureAtlas::addChip(const TextureChip& chip)
{
	_chips[chip.name] = chip;
}

void tool::TextureAtlas::removeChip(const std::string& name)
{
	_chips.erase(name);
}

const tool::TextureChip* tool::TextureAtlas::getChip(const std::string& name) const
{
	auto it = _chips.find(name);
	if (it != _chips.end())
	{
		return &it->second;
	}

	return nullptr;
}

void tool::TextureAtlas::removeAllChips()
{
	_chips.clear();
}

const std::map<std::string, tool::TextureChip>& tool::TextureAtlas::getAllChips() const
{
	return _chips;
}
