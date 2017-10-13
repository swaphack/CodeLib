#include "Audio.h"

using namespace render;

Audio::Audio()
:_data(nullptr)
, _channels(0)
, _channelLayout(0)
, _format(0)
, _frequency(0)
, _size(0)
, _samples(0)
{
	SAFE_FREE(_data);
}

Audio::~Audio()
{
}

uchar* Audio::getData()
{
	return _data;
}

void Audio::setData(uchar* data)
{
	SAFE_FREE(_data);
	_data = data;
}

int Audio::getChannels()
{
	return _channels;
}

void Audio::setChannels(int channels)
{
	_channels = channels;
}

int64_t Audio::getChannelLayout()
{
	return _channelLayout;
}

void Audio::setChannelLayout(int64_t channelLayout)
{
	_channelLayout = channelLayout;
}

int Audio::getFormat()
{
	return _format;
}

void Audio::setFormat(int format)
{
	_format = format;
}

int Audio::getFrequency()
{
	return _frequency;
}

void Audio::setFrequency(int frequency)
{
	_frequency = frequency;
}

int Audio::getSize()
{
	return _size;
}

void Audio::setSize(int size)
{
	_size = size;
}

int Audio::getSamples()
{
	return _samples;
}

void Audio::setSamples(int samples)
{
	_samples = samples;
}
