#include "NProperty.h"

using namespace nature;

NProperty::NProperty()
{
	_value = 0;
	_valueRange = std::make_pair(0, 0);
	resetChangedHandler();
}

NProperty::~NProperty()
{

}

void NProperty::setValue(int value)
{
	bool changed = _value != value;
	if (changed)
	{
		onRunChangedHand();
		_value = value;
	}
}

int NProperty::getValue()
{
	return _value;
}

void NProperty::setMinValue(int value)
{
	_valueRange.first = value;
}

int NProperty::getMinValue()
{
	return _valueRange.first;
}

void NProperty::setMaxValue(int value)
{
	_valueRange.second = value;
}

int NProperty::getMaxValue()
{
	return _valueRange.second;
}

void NProperty::registerChangedHandler(NObject* pTarget, NPropertyChanged handler)
{
	_trigger.first = pTarget;
	_trigger.second = handler;
}

void NProperty::resetChangedHandler()
{
	_trigger.first = nullptr;
	_trigger.second = nullptr;
}

void NProperty::onRunChangedHand()
{
	if (_trigger.first && _trigger.second)
	{
		(_trigger.first->*_trigger.second)(this);
	}
}
