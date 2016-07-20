#include "CtrlImage.h"

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

	Texture2D* texture = G_TEXTURE_CACHE->getTexture2D(_imageDefine);
	if (texture == nullptr)
	{
		return;
	}

	_texFrame->setTextureWithRect(texture);
	this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDeep());
}

const char* CtrlImage::getImagePath()
{
	return _imageDefine.filepath.c_str();
}

void CtrlImage::initSelf()
{
	CtrlFrame::initSelf();
}
