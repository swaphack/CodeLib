#include "Message.h"

#include "system.h"

using namespace idea;

Message::Message(Result* result)
:_result(result)
{
}

Message::~Message()
{
	SAFE_DELETE(_result);
}

Result* Message::getResult()
{
	return _result;
}
