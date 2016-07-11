#include "Result.h"
#include "system.h"

using namespace idea;

Result::Result()
:_type(ERT_NONE)
{

}

Result::~Result()
{

}

ResultType Result::getType()
{
	return _type;
}

void Result::setType(ResultType value)
{
	_type = value;
}

const char* Result::getStringValue()
{
	return nullptr;
}

//////////////////////////////////////////////////////////////////////////
ResultBoolean::ResultBoolean(bool value)
:_value(value)
{
	setType(ERT_BOOLEAN);
}

ResultBoolean::~ResultBoolean()
{

}

bool ResultBoolean::getValue()
{
	return _value;
}

const char* ResultBoolean::getStringValue()
{
	return _value ? "TRUE" : "FALSE";
}

//////////////////////////////////////////////////////////////////////////
ResultNumber::ResultNumber(float value)
:_value(value)
{
	setType(ERT_NUMBER);
}

ResultNumber::~ResultNumber()
{

}

float ResultNumber::getValue()
{
	return _value;
}

const char* ResultNumber::getStringValue()
{
	return getCString("%f", _value);
}

//////////////////////////////////////////////////////////////////////////
ResultString::ResultString(const char* value)
:_value(value)
{
	setType(ERT_STRING);
}

ResultString::~ResultString()
{

}

const char* ResultString::getValue()
{
	return _value.c_str();
}

const char* ResultString::getStringValue()
{
	return _value.c_str();
}

//////////////////////////////////////////////////////////////////////////
ResultPtr::ResultPtr(void* value)
:_value(value)
{
	setType(ERT_POINTER);
}

ResultPtr::~ResultPtr()
{
	SAFE_DELETE(_value);
}

void* ResultPtr::getValue()
{
	return _value;
}

const char* ResultPtr::getStringValue()
{
	return (char*)_value;
}

//////////////////////////////////////////////////////////////////////////
ResultRef::ResultRef(void* value)
:_value(value)
{
	setType(ERT_REFERENCE);
}

ResultRef::~ResultRef()
{

}

void* ResultRef::getValue()
{
	return _value;
}

const char* ResultRef::getStringValue()
{
	return (char*)_value;
}
