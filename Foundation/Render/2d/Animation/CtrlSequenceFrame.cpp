#include "CtrlSequenceFrame.h"
#include "2d/UI/CtrlFrame.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture2D.h"

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

	_notify->addListen(NodeNotifyType::ANIMATION, [&](){
		Texture2D* texture = getNextTexture();

		if (texture == nullptr) return;

		if (_ctrlFrame)
		{
			_ctrlFrame->setTextureWithRect(texture);
// 			_ctrlFrame->setSize(this->getWidth(), this->getHeight());
// 			_ctrlFrame->setAnchorPoint(this->getAnchorPoint());
		}
	});

	_notify->addListen(NodeNotifyType::SPACE, [&](){
		if (_ctrlFrame)
		{
			_ctrlFrame->setVolume(this->getWidth(), this->getHeight());
			_ctrlFrame->setAnchorPoint(this->getAnchorPoint());
		}
	});

	return true;
}

void CtrlSequenceFrame::draw()
{
	CtrlAnimation::draw();
}

void CtrlSequenceFrame::setFrameImagePath(const std::string& urlFormat, int count)
{
	_frameImageUrl = urlFormat;
	_frameImageCount = count;
}

const std::string& CtrlSequenceFrame::getFrameImagePath()
{
	return _frameImageUrl;
}

int CtrlSequenceFrame::getFrameImageCount()
{
	return _frameImageCount;
}

Texture2D* CtrlSequenceFrame::getNextTexture()
{
	if (getFrame() >= _frameImageCount)
	{
		setFrame(0);
	}

	const char* imageUrl = getCString(_frameImageUrl.c_str(), getFrame());

	sys::ImageDefine imageDefine;
	imageDefine.filepath = imageUrl;
	imageDefine.format = sys::ImageFormat::PNG;

	Texture2D* texture2D = G_TEXTURE_CACHE->createTexture2D(imageDefine);
	if (texture2D == nullptr)
	{
		return nullptr;
	}
	if (!texture2D->isValid())
	{
		SAFE_DELETE(texture2D);
		return nullptr;
	}
	return texture2D;
}