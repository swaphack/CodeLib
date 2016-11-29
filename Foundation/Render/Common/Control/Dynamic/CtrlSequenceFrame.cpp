#include "CtrlSequenceFrame.h"

using namespace render;


CtrlSequenceFrame::CtrlSequenceFrame()
:_frameImageCount(0)
{

}

CtrlSequenceFrame::~CtrlSequenceFrame()
{

}

bool CtrlSequenceFrame::init()
{
	CtrlAnimation::init();

	_notify->addListen(ENP_ANIMATION_FRAME, [&](){
		Texture2D* texture = getNextTexture();

		if (texture == nullptr) return;

		AUTO_RELEASE_OBJECT(texture);

		if (_ctrlFrame)
		{
			_ctrlFrame->setTextureWithRect(texture);
// 			_ctrlFrame->setVolume(this->getWidth(), this->getHeight(), 0);
// 			_ctrlFrame->setAnchorPoint(this->getAnchorPoint());
		}
	});

	_notify->addListen(ENP_SPACE, [&](){
		if (_ctrlFrame)
		{
			_ctrlFrame->setVolume(this->getWidth(), this->getHeight(), 0);
			_ctrlFrame->setAnchorPoint(this->getAnchorPoint());
		}
	});

	return true;
}

void CtrlSequenceFrame::draw()
{
	CtrlAnimation::draw();
}

void CtrlSequenceFrame::setFrameImagePath(const char* urlFormat, int count)
{
	_frameImageUrl = urlFormat;
	_frameImageCount = count;
}

const char* CtrlSequenceFrame::getFrameImagePath()
{
	return _frameImageUrl.c_str();
}

int CtrlSequenceFrame::getFrameImageCount()
{
	return _frameImageCount;
}

void CtrlSequenceFrame::initSelf()
{
	CtrlAnimation::initSelf();
}

Texture2D* CtrlSequenceFrame::getNextTexture()
{
	if (getFrame() >= _frameImageCount)
	{
		setFrame(0);
	}

	const char* imageUrl = getCString(_frameImageUrl.c_str(), getFrame());

	Ctrl_ImageDefine imageDefine;
	imageDefine.filepath = imageUrl;
	imageDefine.format = EIF_PNG;

	Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);
	if (!texture2D->isEnable())
	{
		delete texture2D;
		return nullptr;
	}
	return texture2D;
}