#include "Method.h"

using namespace idea;

Method::Method()
{

}

Method::~Method()
{
	this->removeAllSteps();
}

void Method::addStep(Step* step)
{
	if (step)
	{
		_steps.push_back(step);
	}
}

void Method::removeStep(Step* step)
{
	std::vector<Step*>::iterator iter = _steps.begin();
	while (iter != _steps.end())
	{
		if (step == *iter)
		{
			delete (*iter);
			_steps.erase(iter);
			break;
		}
		iter++;
	}
}

void Method::removeAllSteps()
{
	std::vector<Step*>::iterator iter = _steps.begin();
	while (iter != _steps.end())
	{
		delete (*iter);
		iter++;
	}

	_steps.clear();
}

Result* Method::run(Event* e)
{
	if (e == nullptr)
	{
		return nullptr;
	}

	Event* stepEvent = new Event();
	stepEvent->setMessage(e->getMessage());
	Result* result;

	// ¥Æ––¥¶¿Ì
	std::vector<Step*>::iterator iter = _steps.begin();
	while (iter != _steps.end())
	{
		result = (*iter)->run(stepEvent);
		if (result)
		{
			stepEvent->setMessage(result);
			iter++;
		}
		else
		{
			break;
		}
	}
	delete stepEvent;

	return result;
}

