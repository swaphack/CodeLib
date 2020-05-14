#include "AudioDetail.h"

using namespace sys;

AudioDetail::AudioDetail()
:_channels(0)
, _channelLayout(0)
, _format(0)
, _frequency(0)
, _samples(0)
{
}

AudioDetail::AudioDetail(const AudioDetail& detail)
{
	this->setData(detail.getData(), detail.getSize());
	this->setChannels(detail.getChannels());
	this->setChannelLayout(detail.getChannelLayout());
	this->setFormat(detail.getFormat());
	this->setFrequency(detail.getFrequency());
	this->setSamples(detail.getSamples());
}

AudioDetail::~AudioDetail()
{
}

uint8_t* AudioDetail::getData() const
{
	return (uint8_t*)_data.getPtr();
}

void AudioDetail::setData(uint8_t* data, int size)
{
	_data.init(size, data);
}

int AudioDetail::getChannels() const
{
	return _channels;
}

void AudioDetail::setChannels(int channels)
{
	_channels = channels;
}

int64_t AudioDetail::getChannelLayout() const
{
	return _channelLayout;
}

void AudioDetail::setChannelLayout(int64_t channelLayout)
{
	_channelLayout = channelLayout;
}

int AudioDetail::getFormat() const
{
	return _format;
}

void AudioDetail::setFormat(int format)
{
	_format = format;
}

int AudioDetail::getFrequency() const
{
	return _frequency;
}

void AudioDetail::setFrequency(int frequency)
{
	_frequency = frequency;
}

int AudioDetail::getSize() const
{
	return _data.getLength();
}

int AudioDetail::getSamples() const
{
	return _samples;
}

void AudioDetail::setSamples(int samples)
{
	_samples = samples;
}

AudioDetail& AudioDetail::operator=(const AudioDetail& detail)
{
	this->setData(detail.getData(), detail.getSize());
	this->setChannels(detail.getChannels());
	this->setChannelLayout(detail.getChannelLayout());
	this->setFormat(detail.getFormat());
	this->setFrequency(detail.getFrequency());
	this->setSamples(detail.getSamples());

	return *this;
}
