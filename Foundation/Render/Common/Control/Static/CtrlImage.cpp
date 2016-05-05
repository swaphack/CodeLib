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
	Node::draw();

	int textID = _texFrame.getTexture()->getTextureID();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	

	GLTool::setColor(getColor());

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textID);
	GLTool::drawRectVertex(&_texRect);
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);
}

void CtrlImage::setImagePath(const char* path, ImageFormat format/* = EIF_PNG*/)
{
	_imageDefine.filepath = path;
	_imageDefine.format = format;

	Texture2D* texture = G_TEXTURE_CACHE->getTexture2D(_imageDefine);
	if (texture == nullptr)
	{
		return;
	}

	_texFrame.setTextureWithRect(texture);
	this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDeep());
}

void CtrlImage::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_texFrame.setTexture(texture);
	setDirty(true);
}

void CtrlImage::setTexRect(sys::Rect rect)
{
	_texFrame.setRect(rect);
	setDirty(true);
} 

void CtrlImage::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr)
	{
		return;
	}

	_texFrame.setTexture(texFrame->getTexture());
	_texFrame.setRect(texFrame->getRect());
	setDirty(true);
}

const TexFrame* CtrlImage::getTexFrame()
{
	return &_texFrame;
}

void CtrlImage::initSelf()
{
	Node::initSelf();

	const Texture* texture = _texFrame.getTexture();
	if (texture == nullptr)
	{
		return;
	}

	sys::Size size = sys::Size(texture->getWidth(), texture->getHeight());
	TextureTool::setTexture2DCoords(&_texRect, size, _texFrame.getRect());

	TextureTool::setTexture2DVertexts(&_texRect, _position, _volume, _anchor);
}
