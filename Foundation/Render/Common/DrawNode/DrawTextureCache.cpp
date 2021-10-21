#include "DrawTextureCache.h"
#include "Common/Texture/import.h"


render::DrawTextureCache::DrawTextureCache()
{

}

render::DrawTextureCache::~DrawTextureCache()
{
	this->removeAllTextures();
}

void render::DrawTextureCache::addTexture(const std::string& name, const std::string& fullpath)
{
	if (fullpath.empty())
	{
		return;
	}

	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(fullpath);
	if (!pTexture)
	{
		return;
	}

	this->addTexture(name, pTexture, fullpath);
}

void render::DrawTextureCache::addTexture(
	const std::string& name, const Texture* texture,
	const std::string& fullpath, const math::Rect& rect, bool rotate)
{
	if (texture == nullptr) return;

	auto it = _textureInfos.find(name);
	if (it == _textureInfos.end())
	{
		TextureInfo info;
		info.name = name;
		info.texture = (Texture*)texture;
		info.fullpath = fullpath;
		info.rect = rect;
		info.rotate = rotate;
		SAFE_RETAIN(info.texture);
		_textureInfos.insert(std::make_pair(name, info));
	}
}

void render::DrawTextureCache::removeTexture(const std::string& name)
{
	auto it = _textureInfos.find(name);
	if (it == _textureInfos.end()) return;
	SAFE_RELEASE(it->second.texture);
	_textureInfos.erase(it);
}

void render::DrawTextureCache::removeAllTextures()
{
	for (auto& item : _textureInfos)
	{
		SAFE_RELEASE(item.second.texture);
	}
	_textureInfos.clear();
}

const render::Texture* render::DrawTextureCache::getTexture(const std::string& name) const
{
	auto it = _textureInfos.find(name);
	if (it == _textureInfos.end())
	{
		return nullptr;
	}

	return it->second.texture;
}

render::Texture* render::DrawTextureCache::getTexture(const std::string& name)
{
	auto it = _textureInfos.find(name);
	if (it == _textureInfos.end())
	{
		return nullptr;
	}

	return it->second.texture;
}
