#include "NStatus.h"

using namespace nature;

NStatus::NStatus()
{
	
	_status = false;
	resetChangedHandler();
}

NStatus::~NStatus()
{

}

void NStatus::setStatus(bool status)
{
	bool changed = _status != status;
	if (changed)
	{
		onRunChangedHand();
		_status = status;
	}
}

bool NStatus::getStatus()
{
	return _status;
}

void NStatus::registerChangedHandler(NObject* pTarget, NStatusChanged handler)
{
	_trigger.first = pTarget;
	_trigger.second = handler;
}

void NStatus::resetChangedHandler()
{
	_trigger.first = nullptr;
	_trigger.second = nullptr;
}

void NStatus::onRunChangedHand()
{
	if (_trigger.first && _trigger.second)
	{
		(_trigger.first->*_trigger.second)(this);
	}
}

