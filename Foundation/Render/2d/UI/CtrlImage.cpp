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

bool CtrlImage::init()
{
	if (!CtrlFrame::init())
	{
		return false;
	}

	return true;
}

void CtrlImage::setImagePath(const std::string& path)
{
	_imageDefine.setFilePath(path);

	this->setTextureWithRect(path);
}

void render::CtrlImage::loadImage(const std::string& path)
{
	_imageDefine.setFilePath(path);

	this->setTexture(path);
}

const std::string& CtrlImage::getImagePath()
{
	return _imageDefine.filepath;
}