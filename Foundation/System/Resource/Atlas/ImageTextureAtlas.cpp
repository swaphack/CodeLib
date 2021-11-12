#include "ImageTextureAtlas.h"

sys::ImageTextureAtlas::ImageTextureAtlas()
{
}

sys::ImageTextureAtlas::~ImageTextureAtlas()
{
	this->removeAllChips();
}
void sys::ImageTextureAtlas::addChip(const std::string& name, int width, int height, int x, int y, bool rotate)
{
	ImageTextureChip chip;
	chip.name = name;
	chip.width = width;
	chip.height = height;
	chip.x = x;
	chip.y = y;
	chip.rotate = rotate;
	this->addChip(chip);
}

void sys::ImageTextureAtlas::addChip(const ImageTextureChip& chip)
{
	this->removeChip(chip.name);
	_chips[chip.name] = chip;
}

void sys::ImageTextureAtlas::removeChip(const std::string& name)
{
	auto it = _chips.find(name);
	if (it == _chips.end()) return;
	_chips.erase(it);
}

const sys::ImageTextureChip* sys::ImageTextureAtlas::getChip(const std::string& name) const
{
	auto it = _chips.find(name);
	if (it != _chips.end())
	{
		return &it->second;
	}

	return nullptr;
}

void sys::ImageTextureAtlas::removeAllChips()
{
	_chips.clear();
}

const std::map<std::string, sys::ImageTextureChip>& sys::ImageTextureAtlas::getAllChips() const
{
	return _chips;
}
