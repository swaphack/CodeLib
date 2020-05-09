#include "CtrlImage.h"
#include "Common/Texture/Texture.h"
#include "Common/Texture/TextureCache.h"

using namespace render;


CtrlImage::CtrlImage()
{

}

CtrlImage::~CtrlImage()
{

}

void CtrlImage::setImagePath(const std::string& path)
{
	_imageDefine.setFilePath(path);

	Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(_imageDefine);
	if (texture == nullptr)
	{
		return;
	}

	this->setTextureWithRect(texture);
}

const std::string& CtrlImage::getImagePath()
{
	return _imageDefine.filepath;
}