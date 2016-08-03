#include "Animation.h"
#include "../Action/import.h"

using namespace render;

Animation::Animation()
:_scheduler(nullptr)
{

}

Animation::~Animation()
{
	this->unregisterScheduler();
	SAFE_DELETE(_scheduler);
}

void Animation::start()
{
	this->registerScheduler();
}

void Animation::pause()
{
	if (_scheduler)
	{
		_scheduler->pause();
	}
}

void Animation::resume()
{
	if (_scheduler)
	{
		_scheduler->resume();
	}
}

void Animation::stop()
{
	this->unregisterScheduler();
}

void Animation::update(float interval)
{
	this->updateSelf(interval);
}

void Animation::registerScheduler()
{
	this->unregisterScheduler();

	if (_scheduler == nullptr)
	{
		_scheduler = new Scheduler();
		_scheduler->setHandler(SEL_ACTION_UPDATE(Animation::update));
	}
	this->getActionProxy()->runAction(_scheduler);
}

void Animation::unregisterScheduler()
{
	if (_scheduler)
	{
		this->getActionProxy()->stopAction(_scheduler);
	}
}

void Animation::updateSelf(float interval)
{

}
