#include "CtrlAnimation.h"
#include "Audio/CtrlAudioSource.h"
#include "Common/Action/import.h"

using namespace render;

CtrlAnimation::CtrlAnimation()
:_speedRatio(1.0f)
, _frameRate(1.0f)
, _frame(0)
, _duration(0)
{
}

CtrlAnimation::~CtrlAnimation()
{
}

bool CtrlAnimation::init()
{
	if (!DrawTexture2D::init())
	{
		return false;
	}

	scheduleUpdate();

	return true;
}

void CtrlAnimation::setSpeedRatio(float ratio)
{
	_speedRatio = ratio;
}

float CtrlAnimation::getSpeedRatio()
{
	return _speedRatio;
}

void CtrlAnimation::setFrameRate(float ratio)
{
	_frameRate = ratio;
}

float CtrlAnimation::getFrameRate()
{
	return _frameRate;
}

void CtrlAnimation::setFrame(int frame)
{
	_frame = static_cast<float>(frame);
	_duration = 0;

	this->notify(NodeNotifyType::ANIMATION);
}

int CtrlAnimation::getFrame()
{
	return static_cast<int>(_frame);
}

void CtrlAnimation::update(float interval)
{
	_duration += interval * getSpeedRatio();
	if (_duration > getFrameRate())
	{
		_duration -= getFrameRate();
		_frame+=1;

		this->notify(NodeNotifyType::ANIMATION);
	}
}


