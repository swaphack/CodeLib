#include "TextureCache.h"
#include "Texture.h"

#include "system.h"

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

Texture2D* TextureCache::createTexture2D(const sys::ImageDefine& imageDefine)
{
	Texture* texture = getTexture(imageDefine.filepath);
	if (texture)
	{
		return dynamic_cast<Texture2D*>(texture);
	}

	sys::ImageDetail* image = nullptr;
	// png
	if (imageDefine.format == sys::ImageFormat::PNG)
	{
		image = sys::Loader::loadImage<sys::ImagePNG>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::JPEG)
	{
		image = sys::Loader::loadImage<sys::ImageJPEG>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::TARGA)
	{
		image = sys::Loader::loadImage<sys::ImageTarga>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::BMP)
	{
		image = sys::Loader::loadImage<sys::ImageBMP>(imageDefine.filepath);
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

	Texture2D* texture2D = CREATE_OBJECT(Texture2D);
	texture2D->load(image);
	addTexture(imageDefine.filepath.c_str(), texture2D);

	SAFE_DELETE(image);

	return texture2D;
}

Texture2D* TextureCache::createTexture2D(const sys::TextDefine& textDefine)
{
	sys::ImageLabel* image = sys::Loader::loadLabel<sys::ImageLabel>(textDefine);
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = CREATE_OBJECT(Texture2D);
	texture2D->load(image);

	SAFE_DELETE(image);

	return texture2D;
}

Texture2D* TextureCache::createTexture2D(const std::string& path)
{
	auto data = sys::ImageDefine(path);
	return createTexture2D(data);
}


