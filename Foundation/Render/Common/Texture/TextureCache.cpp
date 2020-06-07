#include "TextureCache.h"
#include "Texture.h"
#include "Texture2D.h"
#include "TextureCubeMap.h"
#include "system.h"
#include "Common/struct/enum_common.h"

using namespace render;


TextureCache::TextureCache()
{

}

TextureCache::~TextureCache()
{
	this->removeAllTextures();
}

void TextureCache::addTexture2D(const std::string& path, Texture2D* texture)
{
	if (path.empty() || texture == nullptr)
	{
		return;
	}

	SAFE_RETAIN(texture);

	_texture2Ds[path] = texture;
	_textures[texture->getTextureID()] = texture;
}

void TextureCache::removeTexture(Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	auto iter = _textures.find(texture->getTextureID());
	if (iter != _textures.end())
	{
		SAFE_DELETE(iter->second);
		_textures.erase(iter);
	}
}

void TextureCache::removeTexture2D(const std::string& path)
{
	if (path.empty())
	{
		return;
	}

	auto it = _texture2Ds.find(path);
	if (it == _texture2Ds.end())
	{
		return;
	}

	this->removeTexture(it->second);

	_texture2Ds.erase(it);
}

void TextureCache::removeAllTextures()
{
	auto iter = _textures.begin();
	while (iter != _textures.end())
	{
		SAFE_RELEASE(iter->second);
		iter++;
	}

	_texture2Ds.clear();
}

Texture2D* TextureCache::getTexture2D(const std::string& path)
{
	if (path.empty())
	{
		return nullptr;
	}

	auto it = _texture2Ds.find(path);
	if (it == _texture2Ds.end())
	{
		return nullptr;
	}

	return it->second;
}

Texture2D* TextureCache::createTexture2D(const sys::ImageDefine& imageDefine)
{
	Texture* texture = getTexture2D(imageDefine.filepath);
	if (texture)
	{
		return texture->as<Texture2D>();
	}

	sys::ImageDetail* image = loadImageDetail(imageDefine);

	Texture2D* texture2D = CREATE_OBJECT(Texture2D);
	texture2D->load(image);
	addTexture2D(imageDefine.filepath.c_str(), texture2D);

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

TextureCubeMap* render::TextureCache::createTextureCubeMap(int count, const std::string* images)
{
	if (images == nullptr)
	{
		return nullptr;
	}

	sys::ImageDetail** imageDetails = new sys::ImageDetail*[count];
	TextureCubeMap* textureCubeMap = CREATE_OBJECT(TextureCubeMap);
	for (int i = 0; i < count; i++)
	{
		if (images[i].empty())
		{
			imageDetails[i] = nullptr;
			continue;
		}
		sys::ImageDetail* imageDetail = loadImageDetail(images[i]);
		if (imageDetail)
		{
			CubeFace face = (CubeFace)i;
			if (face != CubeFace::TOP && face != CubeFace::BOTTOM)
			{
				imageDetail->flipY();
				imageDetail->flipX();
			}
		}
		imageDetails[i] = imageDetail;
	}

	textureCubeMap->load(count, imageDetails);
	for (int i = 0; i < count; i++)
	{
		if (imageDetails[i] == nullptr)
		{
			continue;
		}
		SAFE_DELETE(imageDetails[i]);
	}
	delete[] imageDetails;
	return textureCubeMap;
}

sys::ImageDetail* render::TextureCache::loadImageDetail(const std::string& path)
{
	sys::ImageDefine imageDefine(path);

	return loadImageDetail(imageDefine);
}

sys::ImageDetail* render::TextureCache::loadImageDetail(const sys::ImageDefine& imageDefine)
{
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

	return image;
}

Texture2D* TextureCache::createTexture2D(const std::string& path)
{
	auto data = sys::ImageDefine(path);
	return createTexture2D(data);
}


