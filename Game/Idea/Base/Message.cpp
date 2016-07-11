#include "Message.h"

#include "system.h"

using namespace idea;

Message::Message()
:_body(nullptr)
, _type(0)
{

}

Message::~Message()
{
	SAFE_RELEASE(_body);
}

const char* Message::getTitle()
{
	return _title.c_str();
}

void Message::setTitle(const char* title)
{
	_title = title;
}

Result* Message::getBody()
{
	return _body;
}

void Message::setBody(Result* result)
{
	if (result == nullptr)
	{
		return;
	}
	SAFE_RETAIN(result);
	SAFE_RELEASE(_body);
	_body = result;
}

int Message::getType()
{
	return _type;
}

void Message::setType(int value)
{
	_type = value;
}
