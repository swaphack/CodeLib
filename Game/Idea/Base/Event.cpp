#include "Event.h"
#include "system.h"

using namespace idea;

Event::Event()
:_type(0)
{
	_message = new Message();
}

Event::~Event()
{
	SAFE_DELETE(_message);
}

Result* Event::getMessage()
{
	return _message->getBody();
}

void Event::setMessage(Result* result)
{
	ASSERT(result != nullptr);
	_message->setBody(result);
}

int Event::getType()
{
	return _type;
}

void Event::setType(int value)
{
	_type = value;
}