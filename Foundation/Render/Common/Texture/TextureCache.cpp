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
		SAFE_RELEASE(iter->second);
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

std::string render::TextureCache::getTexFrameName(const std::string& path, const std::string name) const
{
	return path + "[" + name + "]";
}

void render::TextureCache::addTexAltas(const std::string& path, const sys::TextureAtlas& texAltas)
{
	Texture* texture = this->createTexture2D(path);
	if (texture)
	{
		this->addTexAltas(path, texture, texAltas);
	}
}

void render::TextureCache::addTexAltas(const std::string& path, const Texture* texture, const sys::TextureAtlas& texAltas)
{
	if (texture == nullptr || texture->getWidth() == 0 || texture->getHeight() == 0)
	{
		return;
	}
	for (const auto& item : texAltas.getAllChips())
	{
		float y = texture->getHeight() - item.second.y - item.second.height;
		if (y < 0)
		{
			PRINT("error: TextureCache::addTexAltas Y value is lower than 0!!!");
			y = 0;
		}
		math::Rect rect(item.second.x, y, item.second.width, item.second.height);
		this->addTexFrame(path, texture, item.first, rect);
	}
}

void render::TextureCache::addTexFrame(const std::string& path, const TexFrame& texFrame)
{
	if (texFrame.getName().empty())
	{
		return;
	}
	std::string fullname = getTexFrameName(path, texFrame.getName());
	_texFrames[fullname] = texFrame;
}

void render::TextureCache::addTexFrame(const std::string& path, const Texture* texture, const std::string& name, const math::Rect& rect)
{
	if (texture == nullptr || texture->getWidth() == 0 || texture->getHeight() == 0) return;

	math::Rect percentRect(rect.getMinX() / texture->getWidth(), rect.getMinY() / texture->getHeight(),
		rect.getWidth() / texture->getWidth(), rect.getHeight() / texture->getHeight());

	TexFrame texFrame;
	texFrame.setName(name);
	texFrame.setRect(percentRect);
	texFrame.setTexture(texture);
	this->addTexFrame(path, texFrame);
}

const TexFrame* render::TextureCache::getTexFrame(const std::string& path, const std::string name) const
{
	std::string fullname = getTexFrameName(path, name);
	return getTexFrame(fullname);
}

const TexFrame* render::TextureCache::getTexFrame(const std::string& pathname) const
{
	auto it = _texFrames.find(pathname);
	if (it != _texFrames.end())
	{
		return &it->second;
	}
	return nullptr;
}

void render::TextureCache::removeTexFrames(const std::string& path)
{
	_texFrames.erase(path);
}

Texture2D* render::TextureCache::createTexture2D(const phy::Color4B& color)
{
	Texture2D* texture2D = CREATE_OBJECT(Texture2D);
	texture2D->load(color);
	return texture2D;
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
	addTexture2D(imageDefine.filepath, texture2D);

	SAFE_DELETE(image);

	return texture2D;
}

Texture2D* TextureCache::createTexture2D(const sys::TextDefine& textDefine)
{
	if (textDefine.fontSize == 0)
	{
		return nullptr;
	}
	sys::LabelImage* image = sys::ResourceLoader::loadLabel<sys::LabelImage>(textDefine);
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
		image = sys::ResourceLoader::loadImage<sys::ImagePNG>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::JPEG)
	{
		image = sys::ResourceLoader::loadImage<sys::ImageJPEG>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::TARGA)
	{
		image = sys::ResourceLoader::loadImage<sys::ImageTarga>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::BMP)
	{
		image = sys::ResourceLoader::loadImage<sys::ImageBMP>(imageDefine.filepath);
	}
	else if (imageDefine.format == sys::ImageFormat::TIFF)
	{
		image = sys::ResourceLoader::loadImage<sys::ImageTIFF>(imageDefine.filepath);
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


