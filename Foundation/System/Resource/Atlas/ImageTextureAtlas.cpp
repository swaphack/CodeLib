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
	ImageTextureChip* chip = CREATE_OBJECT(ImageTextureChip);
	if (chip == nullptr) return;
	chip->name = name;
	chip->width = width;
	chip->height = height;
	chip->x = x;
	chip->y = y;
	chip->rotate = rotate;
	this->addChip(chip);
}

void sys::ImageTextureAtlas::addChip(const ImageTextureChip* chip)
{
	if (chip == nullptr) return;
	auto pChip = (ImageTextureChip*)chip;
	SAFE_RETAIN(pChip);
	this->removeChip(chip->name);
	_chips[chip->name] = pChip;
}

void sys::ImageTextureAtlas::removeChip(const std::string& name)
{
	auto it = _chips.find(name);
	if (it == _chips.end()) return;
	SAFE_RELEASE(it->second);
	_chips.erase(it);
}

const sys::ImageTextureChip* sys::ImageTextureAtlas::getChip(const std::string& name) const
{
	auto it = _chips.find(name);
	if (it != _chips.end())
	{
		return it->second;
	}

	return nullptr;
}

void sys::ImageTextureAtlas::removeAllChips()
{
	for (auto item : _chips)
	{
		SAFE_RELEASE(item.second);
	}
	_chips.clear();
}

const std::map<std::string, sys::ImageTextureChip*>& sys::ImageTextureAtlas::getAllChips() const
{
	return _chips;
}
