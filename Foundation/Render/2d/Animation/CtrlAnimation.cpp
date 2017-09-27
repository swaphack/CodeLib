#include "CtrlAnimation.h"
#include "../UI/CtrlFrame.h"

using namespace render;


CtrlAnimation::CtrlAnimation()
:_speedRatio(1.0f)
, _frameRate(1.0f)
, _frame(0)
, _duration(0)
{
	_ctrlFrame = CREATE_NODE(CtrlFrame);
	this->addChild(_ctrlFrame);

	_ctrlAudio = CREATE_NODE(CtrlAudioSource);
	this->addChild(_ctrlAudio);
}

CtrlAnimation::~CtrlAnimation()
{

}

void CtrlAnimation::draw()
{
	Animation::draw();
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
	onFrameChange();
}

int CtrlAnimation::getFrame()
{
	return static_cast<int>(_frame);
}

CtrlFrame* CtrlAnimation::getMovie()
{
	return _ctrlFrame;
}

void CtrlAnimation::updateSelf(float interval)
{
	_duration += interval * getSpeedRatio();
	if (_duration > getFrameRate())
	{
		_duration -= getFrameRate();
		_frame+=1;
		onFrameChange();
	}
}

void CtrlAnimation::onFrameChange()
{
	setDirty(true);

	_notify->addMark(ENP_ANIMATION_FRAME);
}
