#include "ScriptText.h"
#include "system.h"

#include <cstring>
using namespace math;

ScriptText::ScriptText()
:_capacity(0)
,_value(0)
, _offset(0)
{

}

ScriptText::~ScriptText()
{
	sys::StreamHelper::freeStream(_value);
}

bool ScriptText::loadString(const char* value)
{
	if (value == nullptr)
	{
		return nullptr;
	}
	char* newValue = sys::StreamHelper::mallocStream((char*)value, _capacity);
	if (!standardize(newValue))
	{
		sys::StreamHelper::freeStream(newValue);
		_value = nullptr;
		return false;
	}
	sys::StreamHelper::freeStream(_value);

	_capacity = strlen(value);
	_offset = 0;
	_value = newValue;
	return true;
}

const char* ScriptText::getString()
{
	return _value;
}

bool ScriptText::standardize(char* value)
{
	if (value == nullptr)
	{
		return;
	}

	char* ptr = (char*)value;
	while (*ptr != 0)
	{
		if (*)
		{
		}
		ptr++;
	}
}
