#include "Media.h"
#include "Common/Texture/Texture2D.h"
#include "Audio/CtrlAudioSourceClip.h"
#include "2d/Base/DrawTexture2D.h"
#include "system.h"

using namespace render;

Media::Media()
:_media(nullptr)
{

}

Media::~Media()
{
	SAFE_DELETE(_media);
}

bool Media::init()
{
	if (!Animation::init())
	{
		return false;
	}

	_drawNode = CREATE_NODE(DrawTexture2D);
	this->addChild(_drawNode);

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
			_drawNode->setTextureWithRect(texture);
		}
		sys::AudioDetail* audio = _media->getNextAudio();
		if (audio && audio->getData())
		{
			_ctrlAudio->loadAudioClip(audio);
		}
	});

	return true;
}

void Media::start()
{
	Animation::start();
	if (_ctrlAudio)
	{
		_ctrlAudio->setPaused(false);
	}
}

void Media::pause()
{
	Animation::pause();
	if (_ctrlAudio)
	{
		_ctrlAudio->setPaused(true);
	}
}

void Media::resume()
{
	Animation::resume();
	if (_ctrlAudio)
	{
		_ctrlAudio->setPaused(true);
	}
}

void Media::stop()
{
	Animation::stop();
	if (_ctrlAudio)
	{
		_ctrlAudio->stop();
	}
}

void Media::loadFromURL(const std::string& url, bool defaultSize)
{
	_filepath = url;

	SAFE_DELETE(_media);
	//this->stop();

	_media = sys::ResourceLoader::loadMedia<sys::MediaFFmpeg>(_filepath);
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

Texture2D* Media::getNextTexture()
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
