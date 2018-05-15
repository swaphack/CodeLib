#include "CtrlMedia.h"
#include "../UI/CtrlFrame.h"
#include "Resource/Component/Media.h"
#include "Resource/Loader/Loader.h"
#include "Resource/Paser/FFmpeg.h"

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
		if (_media == nullptr)
		{
			return;
		}

		_media->autoNextFrame();

		Texture2D* texture = getNextTexture();
		if (texture)
		{
			AUTO_RELEASE_OBJECT(texture);

			if (_ctrlFrame)
			{
				_ctrlFrame->setTextureWithRect(texture);
			}
		}		

		Audio* audio = _media->getNextAudio();
		if (audio && audio->getData())
		{
			_ctrlAudio->loadDataFromClip(audio);
		}
	});

	_notify->addListen(ENP_SPACE, [&](){
		if (_ctrlFrame)
		{
			_ctrlFrame->setVolume(this->getWidth(), this->getHeight());
			_ctrlFrame->setAnchorPoint(this->getAnchorPoint());
		}
	});

	return true;
}

void CtrlMedia::draw()
{
	CtrlAnimation::draw();
}

void CtrlMedia::start()
{
	CtrlAnimation::start();
	if (_ctrlAudio)
	{
		_ctrlAudio->setPaused(false);
	}
}

void CtrlMedia::pause()
{
	CtrlAnimation::pause();
	if (_ctrlAudio)
	{
		_ctrlAudio->setPaused(true);
	}
}

void CtrlMedia::resume()
{
	CtrlAnimation::resume();
	if (_ctrlAudio)
	{
		_ctrlAudio->setPaused(true);
	}
}

void CtrlMedia::stop()
{
	CtrlAnimation::stop();
	if (_ctrlAudio)
	{
		_ctrlAudio->stop();
	}
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
		this->setVolume(static_cast<float>(_media->getWidth()), static_cast<float>(_media->getHeight()));
		_ctrlFrame->setVolume(this->getWidth(), this->getHeight());
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

	const Image* image = _media->getNextPicture();
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
