#include "Event.h"
#include "system.h"

using namespace idea;

Event::Event()
{
	_message = new Message();
}

Event::~Event()
{
	SAFE_DELETE(_message);
}

void Event::setMessage(Message* message)
{
	ASSERT(message != nullptr);
	SAFE_DELETE(_message);
	_message = message;
}

Message* Event::getMessage()
{
	return _message;
}