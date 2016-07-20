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

void CtrlMedia::draw()
{
	CtrlAnimation::draw();
}

void CtrlMedia::setMediaPath(const char* path)
{
	_mediaDefine.filepath = path;

	SAFE_DELETE(_media);
	this->stop();

	_media = Resource::load<FFmpeg>(_mediaDefine);

	this->setVolume(_media->getWidth(), _media->getHeight(), 0);

	this->setFrameRate(1.0f / _media->getFrameRate());

	_ctrlFrame->setVolume(this->getWidth(), this->getHeight(), 0);
}	

void CtrlMedia::initSelf()
{
	CtrlAnimation::initSelf();

	if (_media)
	{
		_media->autoNextFrame();
	}

	Texture2D* texture = getNextTexture();

	if (texture == nullptr) return;

	AUTO_RELEASE_OBJECT(texture);

	if (_ctrlFrame)
	{
		_ctrlFrame->setTexture(texture);
		_ctrlFrame->setTexRect(sys::Rect(0, 0, this->getWidth(), this->getHeight()));
		_ctrlFrame->setVolume(this->getWidth(), this->getHeight(), 0);
	}
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

	return texture2D;
}
