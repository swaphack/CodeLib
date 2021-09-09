#include "CtrlScale9Image.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Tool/Tool.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"

using namespace ui;
using namespace render;

ui::CtrlScale9Image::CtrlScale9Image()
{
	_texture2D = CREATE_NODE(render::DrawScale9Texture2D);
	this->addChild(_texture2D);
}

ui::CtrlScale9Image::~CtrlScale9Image()
{
}

bool ui::CtrlScale9Image::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		_texture2D->setVolume(this->getVolume());
		_texture2D->setAnchorPoint(this->getAnchorPoint());
	});

	return true;
}

void ui::CtrlScale9Image::setImagePath(const std::string& path)
{
	_imageDefine.setFilePath(path);

	_texture2D->setTextureWithRect(path);
}

void ui::CtrlScale9Image::loadImage(const std::string& path)
{
	_imageDefine.setFilePath(path);
	_texture2D->setTexture(path);
}

void ui::CtrlScale9Image::loadTexture(const render::Texture* texture)
{
	_texture2D->setTextureWithRect(texture);
}

const std::string& ui::CtrlScale9Image::getImagePath()
{
	return _imageDefine.filepath;
}

void ui::CtrlScale9Image::setMargin(float top, float right, float bottom, float left)
{
	_texture2D->setMargin(top, right, bottom, left);
}

void ui::CtrlScale9Image::setMargin(const sys::CSSMargin& margin)
{
	_texture2D->setMargin(margin);
}

const sys::CSSMargin& ui::CtrlScale9Image::getMargin() const
{
	return _texture2D->getMargin();
}

void ui::CtrlScale9Image::setTexShaderProgram(render::ShaderProgram* shaderProgram)
{
	if (_texture2D)
	{
		_texture2D->setShaderProgram(shaderProgram);
	}
}

render::DrawScale9Texture2D* ui::CtrlScale9Image::getRenderNode() const
{
	return _texture2D;
}

void ui::CtrlScale9Image::setImageColor(const phy::Color4B& color)
{
	_texture2D->setColor(color);
}

phy::Color4B ui::CtrlScale9Image::getImageColor() const
{
	phy::Color4B color;
	phy::convertColor4FTo4B(_texture2D->getColor(), color);
	return color;
}

void ui::CtrlScale9Image::setImageBlend(const render::BlendParam& blend)
{
	_texture2D->setBlend(blend);
}

const render::BlendParam& ui::CtrlScale9Image::getImageBlend() const
{
	return _texture2D->getBlend();
}
