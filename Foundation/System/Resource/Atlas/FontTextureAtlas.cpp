#include "FontTextureAtlas.h"

sys::FontTextureAtlas::FontTextureAtlas()
{
}

sys::FontTextureAtlas::~FontTextureAtlas()
{
	this->removeAllChips();
}

uint32_t sys::FontTextureAtlas::getFontSize() const
{
	return _fontSize;
}

void sys::FontTextureAtlas::setFontSize(uint32_t val)
{
	_fontSize = val;
}

uint32_t sys::FontTextureAtlas::getLineHeight() const
{
	return _lineHeight;
}

void sys::FontTextureAtlas::setLineHeight(uint32_t val)
{
	_lineHeight = val;
}

void sys::FontTextureAtlas::addChip(const std::string& name, int width, int height, int x, int y, bool rotate,
	int advX, int advY, int deltaX, int deltaY)
{
	FontTextureChip chip;
	chip.name = name;
	chip.width = width;
	chip.height = height;
	chip.x = x;
	chip.y = y;
	chip.rotate = rotate;
	chip.advX = advX;
	chip.advY = advY;
	chip.deltaX = deltaX;
	chip.deltaY = deltaY;
	this->removeChip(name);
	_chips[name] = chip;
}

void sys::FontTextureAtlas::addChip(const FontTextureChip& chip)
{
	this->removeChip(chip.name);
	_chips[chip.name] = chip;
}

void sys::FontTextureAtlas::removeChip(const std::string& name)
{
	auto it = _chips.find(name);
	if (it == _chips.end()) return;
	_chips.erase(it);
}

const sys::FontTextureChip* sys::FontTextureAtlas::getChip(const std::string& name) const
{
	auto it = _chips.find(name);
	if (it != _chips.end())
	{
		return &it->second;
	}

	return nullptr;
}

void sys::FontTextureAtlas::removeAllChips()
{
	_chips.clear();
}

const std::map<std::string, sys::FontTextureChip>& sys::FontTextureAtlas::getAllChips() const
{
	return _chips;
}
