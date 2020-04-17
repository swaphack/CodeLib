#include "TextureCache.h"
#include "Texture.h"

#include "Resource/Config/ImageDefine.h"
#include "Resource/Config/TextDefine.h"
#include "Resource/Loader/Loader.h"
#include "Resource/Paser/import.h"

using namespace render;


TextureCache::TextureCache()
{

}

TextureCache::~TextureCache()
{
	this->removeAllTextures();
}

void TextureCache::addTexture(const std::string& path, Texture* texture)
{
	if (path.empty() || texture == nullptr)
	{
		return;
	}

	SAFE_RETAIN(texture);

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

void TextureCache::removeTexture(const std::string& path)
{
	if (path.empty())
	{
		return;
	}

	auto it = _textures.find(path);
	if (it == _textures.end())
	{
		return;
	}
	it->second->release();
	_textures.erase(it);
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

Texture* TextureCache::getTexture(const std::string& path)
{
	if (path.empty())
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

Texture2D* TextureCache::createTexture2D(const ImageDefine& imageDefine)
{
	Texture* texture = getTexture(imageDefine.filepath.c_str());
	if (texture)
	{
		return dynamic_cast<Texture2D*>(texture);
	}

	ImageDetail* image = nullptr;
	// png
	if (imageDefine.format == EIF_PNG)
	{
		image = Loader::load<ImagePNG>(imageDefine.filepath);
	}
	else if (imageDefine.format == EIF_JPEG)
	{
		image = Loader::load<ImageJPEG>(imageDefine.filepath);
	}
	else if (imageDefine.format == EIF_TARGA)
	{
		image = Loader::load<ImageTarga>(imageDefine.filepath);
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

Texture2D* TextureCache::createTexture2D(const TextDefine& textDefine)
{
	ImageLabel* image = Loader::load<ImageLabel>(textDefine);
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = new Texture2D();
	texture2D->load(image);
	AUTO_RELEASE_OBJECT(texture2D);

	SAFE_DELETE(image);

	return texture2D;
}

Texture2D* TextureCache::createTexture2D(const std::string& path)
{
	auto data = ImageDefine(path);
	return createTexture2D(data);
}


