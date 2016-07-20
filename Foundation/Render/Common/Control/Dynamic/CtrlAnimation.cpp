#include "CtrlAnimation.h"

using namespace render;


CtrlAnimation::CtrlAnimation()
:_speedRatio(1.0f)
, _frameRate(1.0f)
, _frame(0)
, _duration(0)
{
	_ctrlFrame = new CtrlFrame();
	AUTO_RELEASE_OBJECT(_ctrlFrame);
	this->addChild(_ctrlFrame);
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
	_frame = frame;
	_duration = 0;
	setDirty(true);
}

int CtrlAnimation::getFrame()
{
	return _frame;
}

void CtrlAnimation::updateSelf(float interval)
{
	_duration += interval * getSpeedRatio();
	if (_duration > getFrameRate())
	{
		_duration -= getFrameRate();
		_frame+=1;
		setDirty(true);
	}
}
