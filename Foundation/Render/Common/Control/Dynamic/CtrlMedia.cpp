#include "CtrlMedia.h"

using namespace render;

CtrlMedia::CtrlMedia()
:_media(nullptr)
{
	_ctrlFrame->setCounter(true);
}

CtrlMedia::~CtrlMedia()
{
	SAFE_DELETE(_media);
}

bool CtrlMedia::init()
{
	CtrlAnimation::init();

	_notify->addListen(ENP_ANIMATION_FRAME, [&](){
		if (_media)
		{
			_media->autoNextFrame();
		}

		Texture2D* texture = getNextTexture();

		if (texture == nullptr) return;

		AUTO_RELEASE_OBJECT(texture);

		if (_ctrlFrame)
		{
			_ctrlFrame->setTextureWithRect(texture);
		}
	});

	_notify->addListen(ENP_SPACE, [&](){
		if (_ctrlFrame)
		{
			_ctrlFrame->setSize(this->getWidth(), this->getHeight());
			_ctrlFrame->setAnchorPoint(this->getAnchorPoint());
		}
	});

	return true;
}

void CtrlMedia::draw()
{
	CtrlAnimation::draw();
}

void CtrlMedia::setMediaPath(const char* path, bool defaultSize)
{
	_mediaDefine.filepath = path;

	SAFE_DELETE(_media);
	this->stop();

	_media = Loader::load<FFmpeg>(_mediaDefine);
	this->setFrameRate(1.0f / _media->getFrameRate());

	// ÏÔÊ¾´óÐ¡
	if (defaultSize)
	{
		this->setSize(static_cast<float>(_media->getWidth()), static_cast<float>(_media->getHeight()));
		_ctrlFrame->setSize(this->getWidth(), this->getHeight());
	}
}	

void CtrlMedia::initSelf()
{
	CtrlAnimation::initSelf();
}

Texture2D* CtrlMedia::getNextTexture()
{
	if (_media == nullptr)
	{
		return nullptr;
	}

	const Image* image = _media->getNextVideo();
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = new Texture2D();
	texture2D->load(image);

	if (!texture2D->isEnable())
	{
		delete texture2D;
		return nullptr;
	}

	return texture2D;
}
