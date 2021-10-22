#include "TextureAtlas.h"


sys::TextureAtlas::TextureAtlas()
{
}

sys::TextureAtlas::~TextureAtlas()
{
}

void sys::TextureAtlas::setImage(const std::string& imgFilePath)
{
	_imgFilePath = imgFilePath;
}

const std::string& sys::TextureAtlas::getImagePath() const
{
	return _imgFilePath;
}

void sys::TextureAtlas::setAtlasPath(const std::string& atlasFilePath)
{
	_atlasFilePath = atlasFilePath;
}

const std::string& sys::TextureAtlas::getAltasPath() const
{
	return _atlasFilePath;
}

void sys::TextureAtlas::addChip(const std::string& name, int width, int height, int x, int y, bool rotate)
{
	TextureChip& chip = _chips[name];
	chip.name = name;
	chip.width = width;
	chip.height = height;
	chip.x = x;
	chip.y = y;
	chip.rotate = rotate;
}

void sys::TextureAtlas::addChip(const TextureChip& chip)
{
	_chips[chip.name] = chip;
}

void sys::TextureAtlas::removeChip(const std::string& name)
{
	_chips.erase(name);
}

const sys::TextureChip* sys::TextureAtlas::getChip(const std::string& name) const
{
	auto it = _chips.find(name);
	if (it != _chips.end())
	{
		return &it->second;
	}

	return nullptr;
}

void sys::TextureAtlas::removeAllChips()
{
	_chips.clear();
}

const std::map<std::string, sys::TextureChip>& sys::TextureAtlas::getAllChips() const
{
	return _chips;
}
