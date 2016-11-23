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

	texture->retain();
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

	Image* image = nullptr;
	// png
	if (imageDefine.format == EIF_PNG)
	{
		image = Loader::load<PNGImage>(imageDefine.filepath.c_str());
	}
	else if (imageDefine.format == EIF_JPEG)
	{
		image = Loader::load<JPEGImage>(imageDefine.filepath.c_str());
	}

	if (image == nullptr)
	{
		return nullptr;
	}

	if (image->getPixels() == nullptr)
	{
		SAFE_DELETE(image);
		return nullptr;
	}

	Texture2D* texture2D = new Texture2D();
	texture2D->load(image);
	AUTO_RELEASE_OBJECT(texture2D);
	addTexture(imageDefine.filepath.c_str(), texture2D);

	SAFE_DELETE(image);

	return texture2D;
}

Texture2D* TextureCache::getTexture2D(const TextDefine& textDefine)
{
	LabelImage* image = Loader::load<LabelImage>(textDefine);
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = new Texture2D();
	texture2D->load(image);
	AUTO_RELEASE_OBJECT(texture2D);

	return texture2D;
}


