#include "Animation.h"
#include "Audio/CtrlAudioSource.h"
#include "Common/Action/import.h"

using namespace render;

Animation::Animation()
:_speedRatio(1.0f)
, _frameRate(1.0f)
, _frame(0)
, _duration(0)
{
}

Animation::~Animation()
{
}

bool Animation::init()
{
	if (!Node::init())
	{
		return false;
	}

	scheduleUpdate();

	return true;
}

void Animation::setSpeedRatio(float ratio)
{
	_speedRatio = ratio;
}

float Animation::getSpeedRatio()
{
	return _speedRatio;
}

void Animation::setFrameRate(float ratio)
{
	_frameRate = ratio;
}

float Animation::getFrameRate()
{
	return _frameRate;
}

void Animation::setFrame(int frame)
{
	_frame = static_cast<float>(frame);
	_duration = 0;

	this->notify(NodeNotifyType::ANIMATION);
}

int Animation::getFrame()
{
	return static_cast<int>(_frame);
}

void Animation::update(float interval)
{
	_duration += interval * getSpeedRatio();
	if (_duration > getFrameRate())
	{
		_duration -= getFrameRate();
		_frame+=1;

		this->notify(NodeNotifyType::ANIMATION);
	}
}


