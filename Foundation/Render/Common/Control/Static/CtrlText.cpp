#include "CtrlText.h"

using namespace render;

CtrlText::CtrlText()
:_texFrame(nullptr)
{
}

CtrlText::~CtrlText()
{

}

void CtrlText::draw()
{
	ColorNode::draw();

	if (_texFrame == nullptr || _texFrame->getTexture() == nullptr)
	{
		return;
	}

	GLTool::setColor(getColor());

	int textID = _texFrame->getTexture()->getTextureID();

	GLTool::beginBlend(_blend);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textID);
	GLTool::drawRectVertex(&_texRect);
	glDisable(GL_TEXTURE_2D);

	GLTool::endBlend();
}

void CtrlText::setFontPath(const char* fonturl)
{
	_textDefine.filepath = fonturl;
	setDirty(true);
}

const char* CtrlText::getFontPath()
{
	return _textDefine.filepath.c_str();
}

void CtrlText::setFontSize(float size)
{
	_textDefine.fontSize = size;
	setDirty(true);
}

float CtrlText::getFontSize()
{
	return _textDefine.fontSize;
}

void CtrlText::setHorizontalDistance(float distance)
{
	_textDefine.horizontalDistance = distance;
	setDirty(true);
}

float CtrlText::getHorizontalDistance()
{
	return _textDefine.horizontalDistance;
}

void CtrlText::setVerticalDistance(float distance)
{
	_textDefine.verticalDistance = distance;
	setDirty(true);
}

float CtrlText::getVerticalDistance()
{
	return _textDefine.verticalDistance;
}

void CtrlText::setString(const char* text)
{
	_textDefine.text = text;
	setDirty(true);
}

const char* CtrlText::getString()
{
	return _textDefine.text.c_str();
}

void CtrlText::setHorizontalAlignment(HorizontalAlignment alignment)
{
	_textDefine.horizontalAlignment = alignment;
	setDirty(true);
}

HorizontalAlignment CtrlText::getHorizontalAlignment()
{
	return _textDefine.horizontalAlignment;
}

void CtrlText::setVerticalAlignment(VerticalAlignment alignment)
{
	_textDefine.verticalAlignment = alignment;
	setDirty(true);
}

VerticalAlignment CtrlText::getVerticalAlignment()
{
	return _textDefine.verticalAlignment;
}

void CtrlText::setDimensions(float width, float height)
{
	_textDefine.width = width;
	_textDefine.height = height;
	this->setVolume(width, height, 0);
	setDirty(true);
}

sys::Size CtrlText::getDimensions()
{
	return sys::Size(_textDefine.width, _textDefine.height);
}

void CtrlText::setColor(sys::Color4B color)
{
	_textDefine.color = color;
	setDirty(true);
}

sys::Color4B CtrlText::getColor()
{
	return _textDefine.color;
}

void CtrlText::initSelf()
{
	Texture2D* texture = G_TEXTURE_CACHE->getTexture2D(_textDefine);
	if (texture == nullptr)
	{
		return;
	}

	if (_texFrame == nullptr)
	{
		_texFrame = new TexFrame();
		AUTO_RELEASE_OBJECT(_texFrame);
	}

	_texFrame->setTextureWithRect(texture);
	this->setDimensions(texture->getWidth(), texture->getHeight());

	Node::initSelf();

	TextureTool::setTexture2DVertexts(&_texRect, sys::Vector::Zero, _volume, _anchor);
}


