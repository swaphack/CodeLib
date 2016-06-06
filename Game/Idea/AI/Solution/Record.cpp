#include "Record.h"

using namespace idea;


Record::Record()
:_level(0)
{
	sys::Time* now = sys::Time::getNow();
	_time.setTime(now);
	delete now;
}

Record::~Record()
{

}

const sys::Time* Record::getTime()
{
	return &_time;
}

void Record::setTime(sys::Time* time)
{
	if (time == nullptr)
	{
		return;
	}
	_time.setTime(time);
}

const char* Record::getText()
{
	return _text.c_str();
}

void Record::setText(const char* text)
{
	if (text == nullptr)
	{
		return;
	}

	_text = text;
}
