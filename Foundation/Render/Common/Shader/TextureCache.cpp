#include "TextureCache.h"

using namespace render;


TextureCache::TextureCache()
{

}

TextureCache::~TextureCache()
{
	this->removeAllTextures();
}

void TextureCache::addTexture(const char* path, Texture* texture)
{
	if (path == nullptr || texture == nullptr)
	{
		return;
	}

	AUTO_RELEASE_OBJECT(texture);
	_textures[path] = texture;
}

void TextureCache::removeTexture(Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	std::map<std::string, Texture*>::iterator iter = _textures.begin();
	while (iter != _textures.end())
	{
		if (iter->second == texture)
		{
			texture->release();
			break;
		}
		iter++;
	}
}

void TextureCache::removeAllTextures()
{
	std::map<std::string, Texture*>::iterator iter = _textures.begin();
	while (iter != _textures.end())
	{
		iter->second->release();

		iter++;
	}

	_textures.clear();
}

Texture* TextureCache::getTexture(const char* path)
{
	if (path == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, Texture*>::iterator it = _textures.find(path);
	if (it == _textures.end())
	{
		return nullptr;
	}

	return it->second;
}

Texture2D* TextureCache::getTexture2D(const ImageDefine& imageDefine)
{
	Texture* texture = getTexture(imageDefine.filepath.c_str());
	if (texture)
	{
		return dynamic_cast<Texture2D*>(texture);
	}

	// png
// 	if (imageDefine.format == EIF_PNG)
// 	{
		PNGImage* image = Resource::load<PNGImage>(imageDefine.filepath.c_str());
		if (image == nullptr)
		{
			return nullptr;
		}

		Texture2D* texture2D = new Texture2D();
		texture2D->load(image);
		addTexture(imageDefine.filepath.c_str(), texture2D);

		return texture2D;
//	}

	return nullptr;
}

Texture2D* TextureCache::getTexture2D(const TextDefine& textDefine)
{
	LabelImage* image = Resource::load<LabelImage>(textDefine);
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = new Texture2D();
	texture2D->load(image);
	AUTO_RELEASE_OBJECT(texture2D);

	return texture2D;
}


