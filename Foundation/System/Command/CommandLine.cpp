#include "CommandLine.h"

using namespace sys;


CommandLine::CommandLine()
{

}

CommandLine::~CommandLine()
{

}

void CommandLine::pushCommand(const std::string& line)
{
	if (line.empty())
	{
		return;
	}

	_commandLines.push(line);
}

std::string CommandLine::popCommand()
{
	if (_commandLines.size() == 0)
	{
		return "";
	}
	std::string head = _commandLines.front();
	_commandLines.pop();
	return head;
}

bool CommandLine::empty() const
{
	return _commandLines.empty();
}

void CommandLine::clear()
{
	while (!_commandLines.empty())
	{
		_commandLines.pop();
	}
}
