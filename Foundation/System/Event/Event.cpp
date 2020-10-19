#include "Event.h"

sys::Event::Event()
{
}


sys::Event::~Event()
{
}

void sys::Event::setUserData(void* data)
{
	_userData = data;
}

void* sys::Event::getUserData() const
{
	return _userData;
}
