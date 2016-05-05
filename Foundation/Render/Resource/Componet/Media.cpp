#include "Media.h"

using namespace render;

Media::Media()
:_frameRate(0),
_width(0),
_height(0),
_time(0)
{

}

Media::~Media()
{
}

Image* Media::getNextVideo()
{
	return nullptr;
}

void Media::setVideoFrame(mf_s frame)
{

}

uint Media::getHeight() const
{
	return _height;
}

uint Media::getWidth() const
{
	return _width;
}

float Media::getFrameRate() const
{
	return _frameRate;
}

float Media::getTime() const
{
	return _time;
}

void Media::setHeight(uint val)
{
	_height = val;
}

void Media::setWidth(uint val)
{
	_width = val;
}

void Media::setFrameRate(float val)
{
	_frameRate = val;
}

void Media::setTime(float val)
{
	_time = val;
}
