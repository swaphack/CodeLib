#include "CtrlSequenceFrame.h"

using namespace render;


CtrlSequenceFrame::CtrlSequenceFrame()
:_frameCount(0)
{

}

CtrlSequenceFrame::~CtrlSequenceFrame()
{

}

void CtrlSequenceFrame::draw()
{
	CtrlAnimation::draw();
}

void CtrlSequenceFrame::setFramePath(const char* urlFormat, int count)
{
	_frameUrlFormat = urlFormat;
	_frameCount = count;
}

void CtrlSequenceFrame::initSelf()
{
	CtrlAnimation::initSelf();

	Texture2D* texture = getNextTexture();

	if (texture == nullptr) return;

	if (_ctrlFrame)
	{
		_ctrlFrame->setTexture(texture);
		_ctrlFrame->setTexRect(sys::Rect(0, 0, texture->getWidth(), texture->getHeight()));
		_ctrlFrame->setVolume(texture->getWidth(), texture->getHeight(), 0);
	}
}

Texture2D* CtrlSequenceFrame::getNextTexture()
{
	if (getFrame() >= _frameCount)
	{
		setFrame(0);
	}

	const char* imageUrl = getCString(_frameUrlFormat.c_str(), getFrame());

	Ctrl_ImageDefine imageDefine;
	imageDefine.filepath = imageUrl;
	imageDefine.format = EIF_PNG;

	Texture2D* texture = G_TEXTURE_CACHE->getTexture2D(imageDefine);
	return texture;
}
