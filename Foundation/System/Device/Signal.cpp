#include "Signal.h"

using namespace sys;


Signal::Signal()
{

}

Signal::~Signal()
{

}

void Signal::setMessage(void* msg)
{
	_msg = msg;
}

void* Signal::getMessage() const
{
	return _msg;
}
