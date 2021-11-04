#include "TextCache.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TextureCache.h"

render::TextCache::TextCache()
{
}

render::TextCache::~TextCache()
{
}

void render::TextCache::addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const sys::FontTextureAtlas& texAtlas)
{
	Texture* texture = G_TEXTURE_CACHE->createTexture2D(imagePath);
	if (texture)
	{
		this->addTexAtlas(imagePath, atlasPath, texture, texAtlas);
	}
}

void render::TextCache::addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const Texture* texture, const sys::FontTextureAtlas& texAtlas)
{
	if (texture == nullptr || texture->getWidth() == 0 || texture->getHeight() == 0)
	{
		return;
	}
	_fontAtlas[atlasPath] = texAtlas;
}

const sys::FontTextureAtlas* render::TextCache::getFontAtlas(const std::string& atlasPath) const
{
	auto it = _fontAtlas.find(atlasPath);
	if (it == _fontAtlas.end()) return nullptr;

	return &it->second;
}

const sys::FontTextureChip* render::TextCache::getCharData(const std::string& atlasPath, uint64_t ch) const
{
	auto it = _fontAtlas.find(atlasPath);
	if (it == _fontAtlas.end()) return nullptr;

	return it->second.getChip(getCharName(ch));
}

const sys::FontTextureChip* render::TextCache::getCharData(const std::string& atlasPath, const std::string& name) const
{
	auto it = _fontAtlas.find(atlasPath);
	if (it == _fontAtlas.end()) return nullptr;

	return it->second.getChip(name);
}

std::string render::TextCache::getAtlasName(const std::string& atlasPath, const std::string& name, bool preload)
{
	std::string charName = G_TEXTURE_CACHE->getFrameName(atlasPath, name);
	if (preload)
	{
		auto pTexFrame = G_TEXTURE_CACHE->getTexFrame(charName);
		if (pTexFrame == nullptr)
		{
			_preloadTexFrame(atlasPath, name);
		}
	}
	return charName;
}

std::string render::TextCache::getCharName(uint64_t ch) const
{
	return getCString("%ld", ch);
}

void render::TextCache::_preloadTexFrame(const std::string& atlasPath, const std::string& name)
{
	auto pTextureAtlas = getFontAtlas(atlasPath);
	if (pTextureAtlas)
	{
		auto pCharData = pTextureAtlas->getChip(name);
		if (pCharData)
		{
			auto pTexture = G_TEXTURE_CACHE->getTexture2D(pTextureAtlas->getImagePath());
			if (pTexture)
			{
				float y = pTexture->getHeight() - pCharData->y - pCharData->height;
				if (y < 0)
				{
					PRINTLN("error: TextureCache::addTexAtlas Y value is lower than 0!!!");
					y = 0;
				}
				math::Rect rect(pCharData->x, y, pCharData->width, pCharData->height);
				G_TEXTURE_CACHE->addTexFrame(atlasPath, pTexture, name, rect, pCharData->rotate, false);
			}
		}
	}
}
