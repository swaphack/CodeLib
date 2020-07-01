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

	this->setTextureWithRect(path);
}

const std::string& CtrlImage::getImagePath()
{
	return _imageDefine.filepath;
}