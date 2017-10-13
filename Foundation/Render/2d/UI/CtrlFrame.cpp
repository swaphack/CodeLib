#include "CtrlFrame.h"

using namespace render;

CtrlFrame::CtrlFrame()
:_bFlipX(false)
, _bFlipY(false)
, _bCounter(false)
{
	_texFrame = new TexFrame();
}

CtrlFrame::~CtrlFrame()
{
	SAFE_DELETE(_texFrame);
}

bool CtrlFrame::init()
{
	ColorNode::init();

	_notify->addListen(ENP_SPACE, [this](){
		onTextureChange();
	});

	_notify->addListen(ENP_TEXTURE_FRAME, [this](){
		onTextureChange();
	});


	return true;
}

void CtrlFrame::draw()
{
	ColorNode::draw();

	if (_texFrame->getTexture() == nullptr)
	{
		return;
	}

	int textID = _texFrame->getTexture()->getTextureID();

	G_DRAWCOMMANDER->addCommand(DCTexture::create(textID, &_texRect, _color, _opacity, _blend));
}

void CtrlFrame::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_texFrame->setTexture(texture);
	setDirty(true);
	_notify->addMark(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTextureWithRect(const Texture* texture)
{
	_texFrame->setTextureWithRect(texture);
	setDirty(true);
	_notify->addMark(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTexRect(const sys::Rect& rect)
{
	_texFrame->setRect(rect);
	setDirty(true);
	_notify->addMark(ENP_TEXTURE_FRAME);
} 

void CtrlFrame::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr)
	{
		return;
	}

	*_texFrame = *texFrame;
	setDirty(true);
	_notify->addMark(ENP_TEXTURE_FRAME);
}

const TexFrame* CtrlFrame::getTexFrame()
{
	return _texFrame;
}

void CtrlFrame::setFlipX(bool status)
{
	_bFlipX = status;
	setDirty(true);
	_notify->addMark(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipX()
{
	return _bFlipX;
}

void CtrlFrame::setFlipY(bool status)
{
	_bFlipY = status;
	setDirty(true);
	_notify->addMark(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipY()
{
	return _bFlipY;
}

bool CtrlFrame::isCounter()
{
	return _bCounter;
}

void CtrlFrame::setCounter(bool status)
{
	_bCounter = status;
}

void CtrlFrame::initSelf()
{
	ColorNode::initSelf();
}

void CtrlFrame::onTextureChange()
{
	const Texture* texture = _texFrame->getTexture();
	if (texture == nullptr)
	{
		return;
	}

	sys::Size size = sys::Size(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));

	if (isCounter())TextureTool::setTexture2DCounterCoords(&_texRect, size, _texFrame->getRect());
	else TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());

	TextureTool::setTexture2DVertexts(&_texRect, sys::Vector3::Zero, _volume, _anchor);
	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
}