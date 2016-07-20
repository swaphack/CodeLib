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

void CtrlFrame::draw()
{
	ColorNode::draw();

	int textID = _texFrame->getTexture()->getTextureID();

	GLTool::beginBlend(_blend);

	GLTool::setColor(getColor());

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textID);
	GLTool::drawRectVertex(&_texRect);
	glDisable(GL_TEXTURE_2D);

	GLTool::endBlend();
}

void CtrlFrame::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_texFrame->setTexture(texture);
	setDirty(true);
}

void CtrlFrame::setTexRect(const sys::Rect& rect)
{
	_texFrame->setRect(rect);
	setDirty(true);
} 

void CtrlFrame::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr)
	{
		return;
	}

	_texFrame->setTexture(texFrame->getTexture());
	_texFrame->setRect(texFrame->getRect());
	setDirty(true);
}

const TexFrame* CtrlFrame::getTexFrame()
{
	return _texFrame;
}

void CtrlFrame::setFlipX(bool status)
{
	_bFlipX = status;
	setDirty(true);
}

bool CtrlFrame::isFlipX()
{
	return _bFlipX;
}

void CtrlFrame::setFlipY(bool status)
{
	_bFlipY = status;
	setDirty(true);
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
	Node::initSelf();

	const Texture* texture = _texFrame->getTexture();
	if (texture == nullptr)
	{
		return;
	}

	sys::Size size = sys::Size(texture->getWidth(), texture->getHeight());

	if (isCounter())TextureTool::setTexture2DCounterCoords(&_texRect, size, _texFrame->getRect());
	else TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());
	TextureTool::setTexture2DVertexts(&_texRect, sys::Vector::Zero, _volume, _anchor);

	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
}