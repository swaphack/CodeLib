#include "Command.h"

#include "system.h"

using namespace web;


Command::Command()
{
	_msg = "";
	_bFullCommand = true;
}

Command::~Command()
{

}

void Command::setMessage(const char* msg, int size)
{
	_msg = std::string(msg, size);
}

const char* Command::getMessage()
{
	return _msg.c_str();
}

int Command::size()
{
	return _msg.size();
}

bool Command::empty()
{
	return _msg.empty();
}

bool Command::isFullCommand()
{
	return _bFullCommand;
}

void Command::setFullCommand(bool status)
{
	_bFullCommand = status;
}
