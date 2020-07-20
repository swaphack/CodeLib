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

	this->addTexture(name, pTexture);
}

void render::DrawTextureCache::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);

	_textures.erase(it);
}

void render::DrawTextureCache::removeAllTextures()
{
	for (auto item : _textures)
	{
		SAFE_RELEASE(item.second);
	}
	_textures.clear();
}

render::Texture* render::DrawTextureCache::getTexture(const std::string& name) const
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return nullptr;
	}

	return it->second;
}

void render::DrawTextureCache::addTexture(const std::string& name, const Texture* id)
{
	if (id == nullptr)
	{
		return;
	}
	this->removeTexture(name);

	Texture* pid = (Texture*)id;
	SAFE_RETAIN(pid);

	_textures[name] = pid;
}

