#include "CtrlAnimation.h"
#include "2d/UI/CtrlFrame.h"
#include "Common/Audio/CtrlAudioSource.h"
#include "Common/Action/import.h"

using namespace render;

CtrlAnimation::CtrlAnimation()
:_speedRatio(1.0f)
, _frameRate(1.0f)
, _frame(0)
, _duration(0)
{
	_ctrlFrame = CREATE_NODE(CtrlFrame);
	this->addChild(_ctrlFrame);
}

CtrlAnimation::~CtrlAnimation()
{
	this->unregisterScheduler();
	SAFE_DELETE(_scheduler);
}

void render::CtrlAnimation::start()
{
	this->registerScheduler();
}

void render::CtrlAnimation::pause()
{
	if (_scheduler)
	{
		_scheduler->pause();
	}
}

void render::CtrlAnimation::resume()
{
	if (_scheduler)
	{
		_scheduler->resume();
	}
}

void render::CtrlAnimation::stop()
{
	this->unregisterScheduler();
}

void render::CtrlAnimation::updateAnimation(float interval)
{
	this->updateSelf(interval);
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

CtrlFrame* CtrlAnimation::getAnimationFrame()
{
	return _ctrlFrame;
}

void render::CtrlAnimation::registerScheduler()
{
	this->unregisterScheduler();

	if (_scheduler == nullptr)
	{
		_scheduler = new Scheduler();
		_scheduler->setHandler(this, SCHEDULER_DELEGATE_SCHEDULER(CtrlAnimation::updateAnimation));
	}
	this->getActionProxy()->runAction(_scheduler);
}

void render::CtrlAnimation::unregisterScheduler()
{
	if (_scheduler)
	{
		this->getActionProxy()->stopAction(_scheduler);
	}
}

void CtrlAnimation::updateSelf(float interval)
{
	_duration += interval * getSpeedRatio();
	if (_duration > getFrameRate())
	{
		_duration -= getFrameRate();
		_frame+=1;

		this->notify(NodeNotifyType::ANIMATION);
	}
}

bool CtrlAnimation::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}
	

	return true;
}
