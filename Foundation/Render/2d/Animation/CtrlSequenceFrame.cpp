#include "CtrlSequenceFrame.h"
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

	addNotifyListener(NodeNotifyType::ANIMATION, [&](){
		Texture2D* texture = getNextTexture();

		this->setTextureWithRect(texture);
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