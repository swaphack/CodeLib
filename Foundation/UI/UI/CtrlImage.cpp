#include "CtrlImage.h"
#include "Common/Texture/Texture.h"
#include "Common/Texture/TextureCache.h"

using namespace render;
using namespace ui;

CtrlImage::CtrlImage()
{
	_texture2D = CREATE_NODE(render::DrawTexture2D);
	this->addChild(_texture2D);
}

CtrlImage::~CtrlImage()
{

}

bool CtrlImage::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	this->addNotifyListener(render::NodeNotifyType::BODY, [this]() {
		_texture2D->setVolume(this->getVolume());
		_texture2D->setAnchorPoint(this->getAnchorPoint());
	});

	return true;
}

void CtrlImage::setImagePath(const std::string& path)
{
	_imageDefine.setFilePath(path);

	_texture2D->setTextureWithRect(path);
}

void ui::CtrlImage::loadImage(const std::string& path)
{
	_imageDefine.setFilePath(path);

	_texture2D->setTexture(path);
}

void ui::CtrlImage::loadTexture(const render::Texture* texture)
{
	_texture2D->setTextureWithRect(texture);
}

const std::string& CtrlImage::getImagePath()
{
	return _imageDefine.filepath;
}

void CtrlImage::setFlipX(bool status)
{
	_texture2D->setFlipX(status);
}

bool CtrlImage::isFlipX()
{
	return _texture2D->isFlipX();
}

void CtrlImage::setFlipY(bool status)
{
	_texture2D->setFlipY(status);
}

bool CtrlImage::isFlipY()
{
	return _texture2D->isFlipY();
}

void ui::CtrlImage::setImageColor(const phy::Color4B& color)
{
	_texture2D->setColor(color);
}

phy::Color4B ui::CtrlImage::getImageColor() const
{
	phy::Color4B color;
	phy::convertColor4FTo4B(_texture2D->getColor(), color);
	return color;
}

void ui::CtrlImage::setImageBlend(const render::BlendParam& blend)
{
	_texture2D->setBlend(blend);
}

const render::BlendParam& ui::CtrlImage::getImageBlend() const
{
	return _texture2D->getBlend();
}

void ui::CtrlImage::setTexShaderProgram(ShaderProgram* shaderProgram)
{
	if (_texture2D)
	{
		_texture2D->setShaderProgram(shaderProgram);
	}
}

render::DrawTexture2D* ui::CtrlImage::getRenderNode() const
{
	return _texture2D;
}
