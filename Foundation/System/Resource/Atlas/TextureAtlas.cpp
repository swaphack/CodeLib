#include "TextureAtlas.h"


sys::TextureAtlas::TextureAtlas()
{
}

sys::TextureAtlas::~TextureAtlas()
{
	
}

void sys::TextureAtlas::setImagePath(const std::string& imgFilePath)
{
	_imgFilePath = imgFilePath;
}

const std::string& sys::TextureAtlas::getImagePath() const
{
	return _imgFilePath;
}

void sys::TextureAtlas::setAtlasPath(const std::string& atlasFilePath)
{
	_atlasFilePath = atlasFilePath;
}

const std::string& sys::TextureAtlas::getAltasPath() const
{
	return _atlasFilePath;
}

