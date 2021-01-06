#include "CtrlMedia.h"
#include "Common/Texture/Texture2D.h"
#include "Audio/CtrlAudioSourceClip.h"
#include "system.h"
using namespace render;

CtrlMedia::CtrlMedia()
:_media(nullptr)
{

}

CtrlMedia::~CtrlMedia()
{
	SAFE_DELETE(_media);
}

bool CtrlMedia::init()
{
	if (!CtrlAnimation::init())
	{
		return false;
	}

	_ctrlAudio = CREATE_NODE(CtrlAudioSourceClip);
	this->addChild(_ctrlAudio);

	addNotifyListener(NodeNotifyType::ANIMATION, [&](){
		if (_media == nullptr)
		{
			return;
		}

		_media->autoNextFrame();

		Texture2D* texture = getNextTexture();
		if (texture)
		{
			this->setTextureWithRect(texture);
		}
		sys::AudioDetail* audio = _media->getNextAudio();
		if (audio && audio->getData())
		{
			_ctrlAudio->loadAudioClip(audio);
		}
	});

	return true;
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

void CtrlMedia::loadFromURL(const std::string& url, bool defaultSize)
{
	_filepath = url;

	SAFE_DELETE(_media);
	//this->stop();

	_media = sys::Loader::loadMedia<sys::MediaFFmpeg>(_filepath);
	if (!_media)
	{
		return;
	}
	this->setFrameRate(1.0f / _media->getFrameRate());

	// Ä¬ÈÏ´óÐ¡
	if (defaultSize)
	{
		this->setVolume(static_cast<float>(_media->getWidth()), static_cast<float>(_media->getHeight()));
		this->setVolume(this->getWidth(), this->getHeight());
	}
}	

Texture2D* CtrlMedia::getNextTexture()
{
	if (_media == nullptr)
	{
		return nullptr;
	}

	const sys::ImageDetail* image = _media->getNextPicture();
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = CREATE_OBJECT(Texture2D);
	texture2D->load(image);

	if (!texture2D->isValid())
	{
		delete texture2D;
		return nullptr;
	}

	return texture2D;
}
