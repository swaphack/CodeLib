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
	for (auto item : _texAtlasFrames)
	{
		SAFE_RELEASE(item.second);
	}
	for (auto item : _textures)
	{
		SAFE_RELEASE(item.second);
	}
	_textures.clear();
	_texture2Ds.clear();
	_texAtlasFrames.clear();
	_texAtlas.clear();
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

void render::TextureCache::addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const sys::ImageTextureAtlas& texAtlas)
{
	Texture* texture = this->createTexture2D(imagePath);
	if (texture)
	{
		this->addTexAtlas(imagePath, atlasPath, texture, texAtlas);
	}
}

void render::TextureCache::addTexAtlas(const std::string& imagePath, const std::string& atlasPath, const Texture* texture, const sys::ImageTextureAtlas& texAtlas)
{
	if (texture == nullptr || texture->getWidth() == 0 || texture->getHeight() == 0)
	{
		return;
	}

	//for (const auto& item : texAtlas.getAllChips())
	//{
	//	float y = texture->getHeight() - item.second->y - item.second->height;
	//	if (y < 0)
	//	{
	//		PRINTLN("error: TextureCache::addTexAtlas Y value is lower than 0!!!");
	//		y = 0;
	//	}
	//	math::Rect rect(item.second->x, y, item.second->width, item.second->height);
	//	this->addTexFrame(atlasPath, texture, item.first, rect, item.second->rotate, false);
	//}

	_texAtlas[atlasPath] = texAtlas;
}

std::string render::TextureCache::getFrameName(const std::string& atlasPath, const std::string& name, bool preload)
{
	std::string atlasPathName = _getFrameName(atlasPath, name);
	if (preload)
	{
		auto pTexFrame = getTexFrame(atlasPathName);
		if (pTexFrame == nullptr)
		{
			_preloadTexFrame(atlasPath, name);
		}
	}
	return atlasPathName;
}

const sys::ImageTextureAtlas* render::TextureCache::getTexAtlas(const std::string& atlasPath) const
{
	auto it = _texAtlas.find(atlasPath);
	if (it == _texAtlas.end()) return nullptr;

	return &it->second;
}

void render::TextureCache::removeTexAtlas(const std::string& atlasPath)
{
	auto it = _texAtlas.find(atlasPath);
	if (it == _texAtlas.end()) return;
	const auto& allChips = it->second.getAllChips();
	for (const auto& item : allChips)
	{
		this->removeTexFrame(item.first);
	}
	_texAtlas.erase(it);
}

bool render::TextureCache::containsTexAtlas(const std::string& atlasPath) const
{
	auto it = _texAtlas.find(atlasPath);
	return it != _texAtlas.end();
}

void render::TextureCache::addTexFrame(const std::string& atlasPath, const TexFrame* texFrame, bool cleanup)
{
	if (texFrame->getName().empty())
	{
		return;
	}
	std::string fullname = _getFrameName(atlasPath, texFrame->getName());
	if (cleanup)
	{
		this->removeTexFrame(fullname);
	}
	auto pTexFrame = (TexFrame*)texFrame;
	SAFE_RETAIN(pTexFrame);
	_texAtlasFrames[fullname] = pTexFrame;
}

void render::TextureCache::addTexFrame(const std::string& atlasPath, const Texture* texture, const std::string& name, const math::Rect& rect, bool rotate, bool cleanup)
{
	if (texture == nullptr || texture->getWidth() == 0 || texture->getHeight() == 0) return;

	math::Rect percentRect(rect.getMinX() / texture->getWidth(), rect.getMinY() / texture->getHeight(),
		rect.getWidth() / texture->getWidth(), rect.getHeight() / texture->getHeight());

	TexFrame* texFrame = CREATE_OBJECT(TexFrame);
	texFrame->setName(name);
	texFrame->setRect(percentRect);
	texFrame->setTexture(texture);
	texFrame->setRotate(rotate);
	this->addTexFrame(atlasPath, texFrame, cleanup);
}

const TexFrame* render::TextureCache::getTexFrame(const std::string& atlasPathName, bool preload)
{
	auto pTexFrame = _getTexFrame(atlasPathName);
	if (pTexFrame) return pTexFrame;
	if (preload)
	{
		std::size_t fpos = atlasPathName.find_first_of('[');
		std::size_t epos = atlasPathName.find_first_of(']');
		if (fpos != -1 && epos != -1)
		{
			std::string atlasPath = atlasPathName.substr(0, fpos);
			std::string name = atlasPathName.substr(fpos+1, epos - fpos - 1);
			_preloadTexFrame(atlasPath, name);
		}
		else
		{
			return nullptr;
		}
		
	}
	return _getTexFrame(atlasPathName);
}

const TexFrame* render::TextureCache::getTexFrame(const std::string& atlasPath, const std::string name, bool preload)
{
	std::string atlasPathName = _getFrameName(atlasPath, name);
	auto pTexFrame = _getTexFrame(atlasPathName);
	if (pTexFrame) return pTexFrame;
	if (preload)
	{
		_preloadTexFrame(atlasPath, name);
	}
	return _getTexFrame(atlasPathName);
}

void render::TextureCache::removeTexFrame(const std::string& path)
{
	auto it = _texAtlasFrames.find(path);
	if (it != _texAtlasFrames.end())
	{
		SAFE_RELEASE(it->second);
		_texAtlasFrames.erase(it);
	}
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

std::string render::TextureCache::_getFrameName(const std::string& atlasPath, const std::string& name) const
{
	return atlasPath + "[" + name + "]";
}

const TexFrame* render::TextureCache::_getTexFrame(const std::string& atlasPathName) const
{
	auto it = _texAtlasFrames.find(atlasPathName);
	if (it != _texAtlasFrames.end())
	{
		return it->second;
	}

	return nullptr;
}

void render::TextureCache::_preloadTexFrame(const std::string& atlasPath, const std::string& name)
{
	auto pTextureAtlas = getTexAtlas(atlasPath);
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

Texture2D* TextureCache::createTexture2D(const std::string& path)
{
	auto data = sys::ImageDefine(path);
	return createTexture2D(data);
}


