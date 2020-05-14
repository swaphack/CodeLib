#include "MediaDetail.h"

#include "../Image/ImageDetail.h"
#include "AudioDetail.h"

using namespace sys;

MediaDetail::MediaDetail()
:_frameRate(0),
_width(0),
_height(0),
_time(0)
{

}

MediaDetail::~MediaDetail()
{
}

void MediaDetail::autoNextFrame()
{

}

ImageDetail* MediaDetail::getNextPicture()
{
	return nullptr;
}

AudioDetail* MediaDetail::getNextAudio()
{
	return nullptr;
}

std::string MediaDetail::getNextTitle()
{
	return "";
}

void MediaDetail::setVideoFrame(float frame)
{

}

uint32_t MediaDetail::getHeight() const
{
	return _height;
}

uint32_t MediaDetail::getWidth() const
{
	return _width;
}

float MediaDetail::getFrameRate() const
{
	return _frameRate;
}

float MediaDetail::getTime() const
{
	return _time;
}

void MediaDetail::setHeight(uint32_t val)
{
	_height = val;
}

void MediaDetail::setWidth(uint32_t val)
{
	_width = val;
}

void MediaDetail::setFrameRate(float val)
{
	_frameRate = val;
}

void MediaDetail::setTime(float val)
{
	_time = val;
}
