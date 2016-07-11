#include "IO.h"

using namespace idea;


IO::IO()
{

}

IO::~IO()
{
	this->clearAllMessages();
}

void IO::push(Message* msg)
{
	if (msg == nullptr)
	{
		return;
	}

	msg->retain();
	_msgs.push(msg);
}

Message* IO::pick()
{
	if (_msgs.empty())
	{
		return nullptr;
	}
	Message* msg = _msgs.front();
	msg->release();
	_msgs.pop();

	return msg;
}

void IO::clearAllMessages()
{
	Message* msg;
	while (!_msgs.empty())
	{
		msg = _msgs.front();
		msg->release();
		_msgs.pop();
	}
}
