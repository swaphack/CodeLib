#include "Event.h"
#include "system.h"

using namespace idea;

Event::Event()
:_message(nullptr)
{

}

Event::~Event()
{
	SAFE_DELETE(_message);
}

void Event::setMessage(Message* message)
{
	_message = message;
}

Message* Event::getMessage()
{
	return _message;
}
