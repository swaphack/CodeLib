#include "ActionProtocol.h"

using namespace render;

ActionProtocol::ActionProtocol()
	:_actionStatus(ActionStatus::NONE)
{

}

ActionProtocol::~ActionProtocol()
{

}

void ActionProtocol::pause()
{
	_actionStatus = ActionStatus::PAUSE;
}

void ActionProtocol::resume()
{
	_actionStatus = ActionStatus::RUNNING;
}

void ActionProtocol::start()
{
	_actionStatus = ActionStatus::RUNNING;
}

void ActionProtocol::stop()
{
	_actionStatus = ActionStatus::STOP;
}

bool ActionProtocol::isFinish()
{
	return _actionStatus == ActionStatus::STOP;
}

bool ActionProtocol::isRunning()
{
	return _actionStatus == ActionStatus::RUNNING;
}