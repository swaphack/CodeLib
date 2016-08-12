#include "NBiotic.h"

using namespace nature;


NBiotic::NBiotic()
:_organism(nullptr)
{
	setOutputHandler(nullptr, nullptr);
}

NBiotic::~NBiotic()
{
	if (_organism)
	{
		delete _organism;
		_organism = nullptr;
	}
}

bool NBiotic::init()
{
	if (_organism == nullptr)
	{
		return false;
	}

	_organism->setOutputHandler(this, static_cast<OutputCallback>(&NBiotic::onOuputHandler));

	return true;
}

void NBiotic::update(float dt)
{
	if (_organism)
	{
		_organism->update(dt);
	}
}

const NOrganism* NBiotic::getOrganism()
{
	return _organism;
}

void NBiotic::setOrganism(NOrganism* pOrganism)
{
	if (pOrganism)
	{
		if (_organism)
		{
			delete _organism;
			_organism = nullptr;
		}
		_organism = pOrganism;
	}
}

bool NBiotic::input(NObject* pObject)
{
	if (pObject == nullptr)
	{
		return false;
	}
	if (_organism)
	{
		_organism->input(pObject);
	}

	return true;
}

void NBiotic::setOutputHandler(NObject* pTarget, OutputCallback callback)
{
	_outputCallback.first = pTarget;
	_outputCallback.second = callback;
}

void NBiotic::onOuputHandler(NObject* pObject)
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

void NBiotic::growing()
{

}

bool NBiotic::touch(NObject* pObject)
{
	if (pObject == nullptr)
	{
		return false;
	}

	if (_organism)
	{
		_organism->input(pObject);
	}

	return true;
}

void NBiotic::setFeedbackCallback(NObject* pTarget, OutputCallback callback)
{
	_feedbackCallback.first = pTarget;
	_feedbackCallback.second = callback;
}

void NBiotic::onFeedbackHandler(NObject* pObject)
{
	if (!pObject)
	{
		return;
	}

	if (_feedbackCallback.first && _feedbackCallback.second)
	{
		(_feedbackCallback.first->*_feedbackCallback.second)(pObject);
	}
}
