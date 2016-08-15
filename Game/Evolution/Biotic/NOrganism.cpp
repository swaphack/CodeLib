#include "NOrganism.h"

using namespace nature;


NOrganism::NOrganism()
{

}

NOrganism::~NOrganism()
{

}

void NOrganism::update(float dt)
{

}

bool NOrganism::input(NObject* pObject)
{
	if (pObject == nullptr)
	{
		return false;
	}

	if (!canAddInputTarget(pObject))
	{
		return false;
	}

	TargetHandler* pTargetHandler = new TargetHandler();
	pTargetHandler->Target = pObject;

	_inputTargets.push(pTargetHandler);

	return true;
}

bool NOrganism::canAddInputTarget(NObject* pObject)
{
	if (pObject == nullptr)
	{
		return false;
	}

	return true;
}

void NOrganism::setOutputHandler(NObject* pTarget, OutputCallback callback)
{
	_outputCallback.first = pTarget;
	_outputCallback.second = callback;
}

void NOrganism::onOuputHandler(NObject* pObject)
{
	if (!pObject)
	{
		return;
	}

	if (_outputCallback.first && _outputCallback.second)
	{
		(_outputCallback.first->*_outputCallback.second)(pObject);
	}
}