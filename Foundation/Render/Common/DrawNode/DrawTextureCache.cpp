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

void render::DrawTextureCache::addTexture(const std::string& name, const Texture* texture, const std::string& fullpath)
{
	if (texture == nullptr) return;

	auto it = _textureInfos.find(name);
	if (it == _textureInfos.end())
	{
		TextureInfo info;
		info.name = name;
		info.texture = (Texture*)texture;
		info.fullpath = fullpath;
		info.increase();
		_textureInfos.insert(std::make_pair(name, info));
	}
	else
	{
		it->second.increase();
	}
}

void render::DrawTextureCache::removeTexture(const std::string& name)
{
	auto it = _textureInfos.find(name);
	if (it == _textureInfos.end())
	{
		return;
	}
	it->second.descrease();
	if (it->second.refCount == 0)
	{
		if (it->second.refCount == 0)
		{
			if (it->second.fullpath.empty())
			{
				G_TEXTURE_CACHE->removeTexture(it->second.texture);
			}
			else
			{
				G_TEXTURE_CACHE->removeTexture2D(it->second.fullpath);
			}
		}
		_textureInfos.erase(it);
	}
}

void render::DrawTextureCache::removeAllTextures()
{
	for (auto item : _textureInfos)
	{
		item.second.dispose();
		if (item.second.refCount == 0)
		{
			if (item.second.fullpath.empty())
			{
				G_TEXTURE_CACHE->removeTexture(item.second.texture);
			}
			else
			{
				G_TEXTURE_CACHE->removeTexture2D(item.second.fullpath);
			}
		}
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
/////////////////////////////////////////////////////////////////////////
void render::DrawTextureCache::TextureInfo::increase()
{
	refCount++;
	SAFE_RETAIN(texture);
}

void render::DrawTextureCache::TextureInfo::descrease()
{
	refCount--;
	SAFE_RELEASE(texture);
}

void render::DrawTextureCache::TextureInfo::dispose()
{
	while (refCount > 0)
	{
		this->descrease();
	}
}
