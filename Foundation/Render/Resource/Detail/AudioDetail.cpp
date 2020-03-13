#include "AudioDetail.h"

using namespace render;

AudioDetail::AudioDetail()
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

AudioDetail::~AudioDetail()
{
	SAFE_FREE(_data);
}

uint8_t* AudioDetail::getData()
{
	return _data;
}

void AudioDetail::setData(uint8_t* data)
{
	SAFE_FREE(_data);
	_data = data;
}

int AudioDetail::getChannels()
{
	return _channels;
}

void AudioDetail::setChannels(int channels)
{
	_channels = channels;
}

int64_t AudioDetail::getChannelLayout()
{
	return _channelLayout;
}

void AudioDetail::setChannelLayout(int64_t channelLayout)
{
	_channelLayout = channelLayout;
}

int AudioDetail::getFormat()
{
	return _format;
}

void AudioDetail::setFormat(int format)
{
	_format = format;
}

int AudioDetail::getFrequency()
{
	return _frequency;
}

void AudioDetail::setFrequency(int frequency)
{
	_frequency = frequency;
}

int AudioDetail::getSize()
{
	return _size;
}

void AudioDetail::setSize(int size)
{
	_size = size;
}

int AudioDetail::getSamples()
{
	return _samples;
}

void AudioDetail::setSamples(int samples)
{
	_samples = samples;
}
