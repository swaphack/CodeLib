#include "SequenceFrame.h"
#include "2d/Base/DrawTexture2D.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/Texture2D.h"

using namespace render;


SequenceFrame::SequenceFrame()
:_frameImageCount(0)
{

}

SequenceFrame::~SequenceFrame()
{

}

bool SequenceFrame::init()
{
	if (!Animation::init())
	{
		return false;
	}

	_drawNode = CREATE_NODE(DrawTexture2D);
	this->addChild(_drawNode);

	addNotifyListener(NodeNotifyType::ANIMATION, [&](){
		Texture2D* texture = getNextTexture();
		_drawNode->loadTexture(texture);
	});

	return true;
}

void SequenceFrame::draw()
{
	Animation::draw();
}

void SequenceFrame::setFrameImagePath(const std::string& urlFormat, int count)
{
	_frameImageUrl = urlFormat;
	_frameImageCount = count;
}

const std::string& SequenceFrame::getFrameImagePath()
{
	return _frameImageUrl;
}

int SequenceFrame::getFrameImageCount()
{
	return _frameImageCount;
}

void render::SequenceFrame::setFlipX(bool status)
{
	if (_drawNode == nullptr) return;
	_drawNode->setFlipX(status);
}

bool render::SequenceFrame::isFlipX()
{
	if (_drawNode == nullptr) return false;
	return _drawNode->isFlipX();
}

void render::SequenceFrame::setFlipY(bool status)
{
	if (_drawNode == nullptr) return;
	_drawNode->setFlipY(status);
}

bool render::SequenceFrame::isFlipY()
{
	if (_drawNode == nullptr) return false;
	return _drawNode->isFlipY();
}

Texture2D* SequenceFrame::getNextTexture()
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

DrawNode* render::SequenceFrame::getRenderNode()
{
	return _drawNode;
}
