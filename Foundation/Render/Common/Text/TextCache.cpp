#include "TextCache.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TextureCache.h"

render::TextCache::TextCache()
{
}

render::TextCache::~TextCache()
{
}

void render::TextCache::addTexAtlas(const std::string& path, const sys::FontTextureAtlas& texAtlas)
{
	Texture* texture = G_TEXTURE_CACHE->createTexture2D(path);
	if (texture)
	{
		this->addTexAtlas(path, texture, texAtlas);
	}
}

void render::TextCache::addTexAtlas(const std::string& path, const Texture* texture, const sys::FontTextureAtlas& texAtlas)
{
	if (texture == nullptr || texture->getWidth() == 0 || texture->getHeight() == 0)
	{
		return;
	}
	for (const auto& item : texAtlas.getAllChips())
	{
		float y = texture->getHeight() - item.second->y - item.second->height;
		if (y < 0)
		{
			PRINTLN("error: TextureCache::addTexAtlas Y value is lower than 0!!!");
			y = 0;
		}
		math::Rect rect(item.second->x, y, item.second->width, item.second->height);
		G_TEXTURE_CACHE->addTexFrame(path, texture, item.first, rect, item.second->rotate);
		_fontAtlas[path] = texAtlas;
	}
}

const sys::FontTextureAtlas* render::TextCache::getFontAtlas(const std::string& filepath) const
{
	auto it = _fontAtlas.find(filepath);
	if (it == _fontAtlas.end()) return nullptr;

	return &it->second;
}

const sys::FontTextureChip* render::TextCache::getCharData(const std::string& filepath, uint64_t ch) const
{
	auto it = _fontAtlas.find(filepath);
	if (it == _fontAtlas.end()) return nullptr;

	return it->second.getChip(getCString("%ld", ch));
}
