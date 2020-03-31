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

void CtrlImage::draw()
{
	CtrlFrame::draw();
}

void CtrlImage::setImagePath(const char* path, ImageFormat format /*= EIF_PNG*/)
{
	_imageDefine.filepath = path;
	_imageDefine.format = format;

	Texture2D* texture = G_TEXTURE_CACHE->createTexture2D(_imageDefine);
	if (texture == nullptr)
	{
		return;
	}

	this->setTextureWithRect(texture);
	this->setVolume(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()), static_cast<float>(texture->getDeep()));
}

const char* CtrlImage::getImagePath()
{
	return _imageDefine.filepath.c_str();
}