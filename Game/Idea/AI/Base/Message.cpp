#include "Message.h"

#include "system.h"

using namespace idea;

Message::Message()
:_result(nullptr)
{

}

Message::~Message()
{
	SAFE_RELEASE(_result);
}

Result* Message::getResult()
{
	return _result;
}

void Message::setResult(Result* result)
{
	if (result == nullptr)
	{
		return;
	}
	SAFE_RETAIN(result);
	SAFE_RELEASE(_result);
	_result = result;
}
